#pragma once
#include<iostream>
#include<algorithm>
using namespace std;

struct Node
{
	int Beta;
	int value;
	Node* left;
	Node* right;
	Node(int val) : value(val) , Beta(0), left(nullptr), right(nullptr) {}
};

class BST
{
protected:
	Node* root;
	void insert(Node* N,Node * temp) {

		if (N->value > temp->value)
		{
			if (temp->right == nullptr)
			{
				temp->right = N;
			}
			else
			{
				temp = temp->right;
				insert(N, temp);
			}
		}
		else if (N->value < temp->value)
		{
			if (temp->left == nullptr)
			{
				temp->left = N;
			}
			else
			{
				temp = temp->left;
				insert(N, temp);
			}
		}
}
	int height(Node* N)
	{
		if (root == nullptr) return -1;
		int lh = height(N->left);
		int rh = height(N->right);
		return lh > rh ? lh + 1: rh + 1;
	}
	int balance(Node* N)
	{
		return N->Beta = height(N->left) - height(N->right);
	}
	int maxBalancecalculator(Node * N)
	{
		return N->Beta > N->left->Beta ? maxBalancecalculator(N->left) + 1: maxBalancecalculator(N->right) + 1;
	}
	void traversal(Node * N)
	{
		balance(N);
		traversal(N->left);
		traversal(N->right);
	}
public:
	BST(): root(nullptr){}
	void insertionAVL(int val)
	{
		Node* newNode = new Node(val);
		newNode->left = nullptr;
		newNode->right = nullptr;
		Node* temp = root;
		if (root == nullptr)
		{
			// beta calculate
			root = newNode;
			balance(newNode);
		}
		else
		{
			insert(newNode,root);
			// attach balance factor to each node including newNode
			traversal(newNode);
			Node* imbalance = root;
			temp = root;
			Node* temp1 = root;
			while (true)
			{
				if (temp->Beta > temp1->Beta)
				{
					imbalance = temp;
					temp = temp1->left;
					temp = temp1->right;
				}
			}
		}
	}
};