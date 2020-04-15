// Lesson133.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

//
//  Реализация односвязного списка
//

#include <iostream>
#include <string>
//#include <memory>

using namespace std;

template<class T>
class List
{
public:
	List();
	~List();

	void pop_front();
	void push_back(T data);
	void clear();
	void GetInfo();
	int GetSize() { return Size; }
	T& operator[](const int index);
	void push_front(T data);
	void insert(T data, int index);
	void removeAt(int index);
	void pop_back();

private:
	template<class T>
	class Node
	{
	public:
		Node* pNext;
		T data;
		Node(T data = T(), Node* pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};
	int Size;
	Node<T>* head;
};

template<class T>
List<T>::List()
{
	Size = 0;
	head = nullptr;
}

template<class T>
List<T>::~List()
{
	clear();
}

template<class T>
void List<T>::pop_front()
{
	Node<T>* temp = head;
	head = head->pNext;
	delete temp;
	Size--;
}

template<class T>
void List<T>::push_back(T data)
{
	if (head == nullptr)
	{
		head = new Node<T>(data);
	}
	else
	{
		Node<T>* current = this->head;
		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new Node<T>(data);
	}
	Size++;
}

template<class T>
void List<T>::clear()
{
	while (Size)
	{
		pop_front();
	}
}

template<class T>
void List<T>::GetInfo()
{
	for (int i = 0; i < GetSize(); i++)
	{
		cout << i << " - " << this->operator[](i) << endl;
	}
	cout << endl << "Элементов в списке - " << GetSize() << endl;
}

template<class T>
T& List<T>::operator[](const int index)
{
	int counter = 0;
	Node<T>* current = this->head;
	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->data;
		}
		current = current->pNext;
		counter++;
	}
}

template<class T>
void List<T>::push_front(T data)
{
	head = new Node<T>(data, head);
	Size++;
}

template<class T>
void List<T>::insert(T data, int index)
{
	if (index==0)
	{
		push_front(data);
	}
	else
	{
		Node<T>* previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}
		Node<T>* newNode = new Node<T>(data, previous->pNext);
		previous->pNext = newNode;
		Size++;
	}
}

template<class T>
void List<T>::removeAt(int index)
{
	if (index == 0)
	{
		pop_front();
	}
	else
	{
		Node<T>* previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}
		Node<T>* toDelete = previous->pNext;
		previous->pNext = toDelete->pNext;
		delete toDelete;
		Size--;
	}
}

template<class T>
void List<T>::pop_back()
{
	removeAt(Size - 1);
}



int main()
{
    setlocale(LC_ALL, "ru");

	List<int>lst;
	lst.push_front(5);
	lst.push_front(7);
	lst.push_front(564);
	lst.push_front(68);
	lst.push_front(15);
	lst.GetInfo();
	lst.removeAt(1);
	lst.GetInfo();
	lst.pop_back();
	lst.GetInfo();

    return 0;
}
