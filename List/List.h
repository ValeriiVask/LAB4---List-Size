#pragma once
#include <exception>
#include <stdexcept>

template <typename T>
class List
{
private:
	struct Node
	{
		Node(T value) noexcept
		{
			this->value = value;
			next = nullptr;
			prev = nullptr;
		}
		T value;
		Node* next;
		Node* prev;
	};

	Node* head;
	Node* tail;

public:
	List() noexcept
	{
		head = nullptr;
		tail = nullptr;
	}

	~List()
	{
		while (head != nullptr)
		{
			Node* tmp = head;
			head = head->next;
			delete tmp;
		}
	}

	size_t size() const noexcept
	{
		//TODO Implement the size method that returns the number of items in the list.
		std::terminate();
	}

	void pushFront(T value)
	{
		Node* newNode = new Node(value);
		newNode->next = head;
		if (head != nullptr)
			head->prev = newNode;
		else
			tail = newNode;
		head = newNode;
	}
};
