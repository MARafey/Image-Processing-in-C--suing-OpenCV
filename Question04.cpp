#include<iostream>
#include"Header.h"
using namespace std;

template <typename T>
class node
{
public:
	T start;
	T end;
	node* next;
	node()
	{
		next = NULL;
	}
	node(T i, T j)
	{
		start = i;
		end = j;
		next = NULL;
	}
	void insert(node*& head,T i,T j)
	{
		node* n = new node(i, j);
		node* temp = head;
		if (isEmpty(head))
		{
			head = n;
		}
		else
		{
			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = n;
		}
	}
	bool isEmpty(node* Head)
	{
		if (Head == NULL)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	void print(node*& head)
	{
		node* temp = head;
		while (temp!=NULL)
		{
			cout<<" " << temp->start << " " << temp->end;
			if (temp->start == -1)
			{
				cout << endl;
			}
			temp = temp->next;
		}
	}
	void destroyer(node*& head)
	{
		node* temp = head;
		head = head->next;
		while (head!=NULL)
		{
			delete temp;
			temp = head;
			head = head->next;
		}
		delete head;
	}
};

void linkLIst_pixel_picking(float** arr,int rows,int cols)
{
	node<float>* head = NULL;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (arr[i][j] == 255)
			{
				for (int k = j; k < cols; k++)
				{
					if (arr[i][k] == 0)
					{
						head->insert(head, j, k - 1);
						j = k;
						break;
					}
					if (k + 1 == cols)
					{
						head->insert(head, j, k);
						j = k;
						break;
					}
				}
				if (j + 1 == cols)
				{
					head->insert(head, -1, -1);
				}
			}
			if (j + 1 == cols)
			{
				head->insert(head, -1, -1);
			}
		}
	}
	head->print(head);
	head->destroyer(head);
}

int main()
{
	string path = "D:\mIMD002.bmp";
	Mat img = imread(path);
	float** arr;
	allocate(arr, img.rows, img.cols);
	image_pixel_pickeing(arr, img.rows, img.cols, img);
	linkLIst_pixel_picking(arr, img.rows, img.cols);

}