class DoublyLinkedList : virtual public MyCollection<int>
{
public:
	struct Node
	{
		int data = 0;
		Node* next = nullptr;
		Node* prev = nullptr;
	};

private:
	Node* head = nullptr;
	Node* tail = nullptr;
	int count = 0;

public:

	DoublyLinkedList()
	{
		head = nullptr;
		tail = nullptr;
		count = 0;
	}

	DoublyLinkedList(const DoublyLinkedList& original)
	{
		head = nullptr;
		tail = nullptr;
		count = 0;

		Node* temp = original.head;

		while (temp != 0)
		{
			AddToTail(temp->data);
			temp = temp->next;
		}
	}

	~DoublyLinkedList()
	{
		while (count != 0)
			Clear();
	}

	int GetCount() override
	{
		return count;
	}

	void Clear()
	{
		while (head != nullptr)
		{
			DeleteFromHead();
		}
	}

	bool IsEmpty() const
	{
		return count == 0;
	}

	int LastIndexOf(int data)
	{
		if (IsEmpty())
		{
			return -1;
		}
		Node* temp = head;
		int i = count;
		while (i > 0)
		{
			if (data == temp->data)
			{
				return i;
			}
			i--;
			temp = temp->next;
		}
		return -1;
	}

	void Reverse()
	{
		Node* current = head;
		Node* next;
		Node* prev = nullptr;
		while (current != 0)
		{
			next = current->next;
			current->next = prev;
			prev = current;
			current = next;
		}
		head = prev;
	}

	void AddToHead(int data)
	{
		Node* temp = new Node();
		temp->data = data;
		temp->next = head;
		if (IsEmpty())
		{
			tail = temp;
		}
		else
		{
			head->prev = temp;
		}
		head = temp;
		count++;
	}

	void AddToTail(int data)
	{
		Node* temp = new Node();
		temp->data = data;
		temp->prev = tail;
		if (IsEmpty())
		{
			head = temp;
		}
		else
		{
			tail->next = temp;
		}
		tail = temp;
		count++;
	}

	void DeleteFromHead()
	{
		if (IsEmpty())
		{
			return;
		}
		Node* temp = head;
		head = head->next;
		delete temp;
		if (head == nullptr)
		{
			tail = nullptr;
		}
		else
		{
			head->prev = nullptr;
		}
		count--;
	}

	void DeleteFromTail()
	{
		if (IsEmpty())
		{
			return;
		}
		Node* temp = tail;
		tail = tail->prev;
		delete temp;
		if (tail == nullptr)
		{
			head = nullptr;
		}
		else
		{
			tail->next = nullptr;
		}
		count--;
	}


	int GetElementByIndex(int index)
	{
		if (index < 0 || index >= count)
			throw "Incorrect index";

		Node* temp = head;

		int i = 0;
		while (i < index)
		{
			temp = temp->next;
			i++;
		}

		return temp->data;
	}

	DoublyLinkedList MergeWith(const DoublyLinkedList& list)
	{
		DoublyLinkedList current = *this;

		Node* temp = list.head;

		while (temp != 0)
		{
			current.AddToTail(temp->data);
			temp = temp->next;
		}
		return current;
	}

	void SortAsc()
	{
		Node* current = head;
		int* arr = new int[count];

		for (int i = 0; i < count; i++) {
			arr[i] = current->data;
			current = current->next;
		}
		int tmp = 0;
		for (int i = 0; i < count; i++)
		{
			for (int j = (count - 1); j >= (i + 1); j--)
			{
				if (arr[j] < arr[j - 1])
				{
					tmp = arr[j];
					arr[j] = arr[j - 1];
					arr[j - 1] = tmp;
				}
			}
		}
		current = head;
		for (int i = 0; i < count; i++)
		{
			current->data = arr[i];
			current = current->next;
		}
		delete[] arr;
	}

	void SortDesc()
	{
		Node* current = head;
		int* arr = new int[count];

		for (int i = 0; i < count; i++) {
			arr[i] = current->data;
			current = current->next;
		}
		int tmp = 0;
		for (int i = 0; i < count; i++)
		{
			for (int j = (count - 1); j >= (i + 1); j--)
			{
				if (arr[j] > arr[j - 1])
				{
					tmp = arr[j];
					arr[j] = arr[j - 1];
					arr[j - 1] = tmp;
				}
			}
		}
		current = head;
		for (int i = 0; i < count; i++)
		{
			current->data = arr[i];
			current = current->next;
		}
		delete[] arr;
	}

	void Shuffle()
	{
		Node* current = head;
		int* arr = new int[count];


		for (int i = 0; i < count; i++) {
			arr[i] = current->data;
			current = current->next;
		}
		random_shuffle(arr, arr + count);
		current = head;
		for (int i = 0; i < count; i++)
		{
			current->data = arr[i];
			current = current->next;
		}
		delete[] arr;
	}

	bool Equals(const DoublyLinkedList* list) const
	{
		Node* temp = head;
		Node* temp_list = list->head;
		int i = 0;

		if (count == list->count)
		{
			while (i < count)
			{
				if ((temp->data != temp_list->data))
				{
					return false;
				}
				temp = temp->next;
				temp_list = temp_list->next;
				i++;
			}
		}
		else if (count != list->count)
		{
			return false;
		}

		return true;
	}

	void Print() override
	{
		if (count == 0)
		{
			cout << "Empty list!\n";
		}
		Node* current = head;
		while (current->next != 0)
		{
			cout << current->data << ", ";
			current = current->next;
		}
		cout << current->data << " \n";
	}

	bool operator == (const DoublyLinkedList& list)
	{
		if (count != list.count)
			return false;
		Node* temp = head;
		Node* temp_list = list.head;

		while (temp != 0)
		{
			if (temp->data != temp_list->data)
				return false;
			temp = temp->next;
			temp_list = temp_list->next;
		}
		return true;
	}

	bool operator != (const DoublyLinkedList& list)
	{
		return !(*this == list);
	}

	bool operator >= (const DoublyLinkedList& list)
	{
		if (count > list.count)
			return true;

		if (*this == list)
			return true;
		return false;
	}

	bool operator <= (const DoublyLinkedList& list)
	{
		if (count < list.count)
			return true;

		if (*this == list)
			return true;
		return false;
	}

	bool operator > (const DoublyLinkedList& list)
	{
		if (count > list.count)
			return true;
		return false;
	}

	bool operator < (const DoublyLinkedList& list)
	{
		if (count < list.count)
			return true;
		return false;
	}

	DoublyLinkedList& operator = (const DoublyLinkedList& list)
	{
		if (this == &list)
			return *this;
		this->~DoublyLinkedList();

		Node* temp = list.head;
		while (temp != 0)
		{
			AddToTail(temp->data);
			temp = temp->next;
		}
		return *this;
	}

	DoublyLinkedList operator + (const DoublyLinkedList& list)
	{
		DoublyLinkedList current = *this;

		Node* temp = list.head;

		while (temp != 0)
		{
			current.AddToTail(temp->data);
			temp = temp->next;
		}
		return current;
	}

	void Add(int data) override
	{
		AddToHead(data);
	}

	int Search(int data) override
	{
		if (count == 0)
		{
			return -1;
		}
		Node* temp = head;
		int i = 0;
		while (i < count)
		{
			if (data == temp->data)
			{
				return i;
			}
			i++;
			temp = temp->next;
		}

		return -1;
	}

	void Replace(int data) override
	{
		DeleteFromHead();
		AddToHead(data);
	}

	void Sort() override
	{
		SortAsc();
	}
};

