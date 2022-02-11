class SinglyLinkedList : virtual public MyCollection<int>
{
public:
	struct Node
	{
		int data = 0;
		Node* next = nullptr;
	};

private:
	Node* head = nullptr;
	Node* tail = nullptr;
	int count = 0;

public:
	SinglyLinkedList()
	{
		head = nullptr;
		tail = nullptr;
		count = 0;
	}

	SinglyLinkedList(const SinglyLinkedList& original)
	{
		Node* original_current = original.head;

		while (original_current != nullptr)
		{
			AddToTail(original_current->data);
			original_current = original_current->next;
		}
	}

	~SinglyLinkedList()
	{
		while (count != 0)
			Clear();
	}

	void AddToHead(int data)
	{
		Node* newElem = new Node();
		newElem->data = data;
		newElem->next = head;
		if (head == nullptr)
		{
			tail = newElem;
		}
		head = newElem;
		count++;
	}

	void AddToTail(int data)
	{
		Node* newElem = new Node();
		newElem->data = data;
		if (tail == nullptr)
		{
			head = newElem;
		}
		else
		{
			tail->next = newElem;
		}
		tail = newElem;
		count++;
	}

	void InsertInto(int data, int position)
	{
		if (position >= count)
		{
			AddToTail(data);
			return;
		}
		else if (position <= 0)
		{
			AddToHead(data);
			return;
		}

		Node* newElem = new Node();
		newElem->data = data;
		int i = 1;
		Node* beforeNew = head;
		while (i++ != position)
		{
			beforeNew = beforeNew->next;
		}
		newElem->next = beforeNew->next;
		beforeNew->next = newElem;

		count++;
	}

	void DeleteFromHead()
	{
		if (count == 0)
		{
			return;
		}
		Node* temp = head;
		head = head->next;
		delete temp;
		count--;
		if (head == nullptr)
		{
			tail = nullptr;
		}
	}

	void DeleteFromTail()
	{
		if (count == 0)
		{
			return;
		}
		DeleteByIndex(count - 1);
	}

	void DeleteByIndex(int position)
	{
		if (position <= 0)
		{
			DeleteFromHead();
			return;
		}

		if (position >= count)
		{
			position = count - 1;
		}

		int i = 1;
		Node* beforeDel = head;
		while (i++ != position)
		{
			beforeDel = beforeDel->next;
		}
		Node* sacrifice = beforeDel->next;
		beforeDel->next = sacrifice->next;
		delete sacrifice;
		count--;
		if (beforeDel->next == nullptr)
		{
			tail = beforeDel;
		}
	}

	void Clear()
	{
		while (head != nullptr)
		{
			DeleteFromHead();
		}
	}

	void Print() override
	{
		if (count == 0)
		{
			cout << "Empty list!\n";
			return;
		}
		Node* current = head;
		while (current != nullptr)
		{
			cout << current->data << " ";
			current = current->next;
		}
		cout << "\n";
	}

	int GetCount() override
	{
		return count;
	}

	int IndexOf(int data) const
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

	bool IsEmpty() const
	{

		return !count;
	}

	int LastIndexOf(int data)
	{
		if (IsEmpty())
		{
			return -1;
		}

		Node* current = head;
		int* arr = new int[count];

		for (int i = 0; i < count; i++) {
			arr[i] = current->data;
			current = current->next;
		}

		for (int i = 0; i < count; i++)
		{
			if (arr[i] == data)
			{
				return i;
			}
		}

		delete[] arr;
		return -1;
	}

	void Reverse()
	{

		Node* current = head;
		int* arr = new int[count];

		for (int i = 0; i < count; i++) {
			arr[i] = current->data;
			current = current->next;
		}

		for (int i = 0; i < count; i++)
		{
			arr[i] = arr[count - 1];
			count--;
		}

		current = head;
		for (int i = 0; i < count; i++)
		{
			current->data = arr[i];
			current = current->next;
		}
		delete[] arr;
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

	bool Equals(const SinglyLinkedList* list) const
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

	SinglyLinkedList Clone() const
	{
		SinglyLinkedList* list = new SinglyLinkedList();
		Node* temp = head;

		for (int i = 0; i < count; i++)
		{
			list->AddToTail(temp->data);
			temp = temp->next;
		}
		return *list;
	}

	bool Contains(int data) const
	{
		Node* temp = head;

		int i = 0;
		while (i < count)
		{
			if (data == temp->data)
			{
				return true;
			}
			i++;
			temp = temp->next;
		}
		return false;
	}

	void SetAt(int position, int d)
	{
		Node* current = head;
		for (int i = 0; i < count; i++)
		{
			if (i == position)
			{
				current->data = d;
			}
			current = current->next;
		}
	}

	int* ToArray()
	{
		return operator int* ();
	}

	SinglyLinkedList MergeWith(const SinglyLinkedList& list)
	{
		SinglyLinkedList current = *this;
		Node* current_list = list.head;

		while (current_list != 0)
		{
			AddToTail(current_list->data);
			current_list = current_list->next;
		}
		return current;
	}

	bool operator <(const SinglyLinkedList& list)
	{
		return count < list.count;
	}

	bool operator >(const SinglyLinkedList& list)
	{
		return count > list.count;
	}

	bool operator <=(const SinglyLinkedList& list)
	{
		return count < list.count || count == list.count;
	}

	bool operator >=(const SinglyLinkedList& list)
	{
		return count > list.count || count == list.count;
	}

	bool operator ==(const SinglyLinkedList& list)
	{
		Node* temp = head;
		Node* temp_list = list.head;
		int i = 0;

		if (count == list.count)
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
		else if (count != list.count)
		{
			return false;
		}

		return true;
	}

	bool operator !=(const SinglyLinkedList& list)
	{
		Node* temp = head;
		Node* temp_list = list.head;
		int i = 0;

		if (count == list.count)
		{
			while (i < count)
			{
				if ((temp->data == temp_list->data))
				{
					return false;
				}
				temp = temp->next;
				temp_list = temp_list->next;
				i++;
			}
		}
		return true;
	}

	SinglyLinkedList& operator =(const SinglyLinkedList& list)
	{
		if (this == &list)
			return *this;
		this->~SinglyLinkedList();

		Node* list_current = list.head;

		while (list_current != nullptr)
		{
			AddToTail(list_current->data);
			list_current = list_current->next;
		}
		return *this;
	}

	const int& operator [](int index) const
	{
		Node* temp = head;
		int i = 0;
		if (index >= 0 && index < count - 1)
		{
			while (i < count)
			{
				if (i == index)
				{
					return temp->data;
				}
				temp = temp->next;
				i++;
			}
		}
		else
		{
			index = 0;
		}
	}

	SinglyLinkedList& operator +(const SinglyLinkedList& list)
	{
		SinglyLinkedList current = *this;

		Node* temp = list.head;

		while (temp != 0)
		{
			current.AddToTail(temp->data);
			temp = temp->next;
		}
		return current;
	}

	operator int* ()
	{
		int* arr = new int[count];

		Node* temp = head;
		int i = 0;
		for (i = 0; i < count; i++)
		{
			arr[i] = temp->data;
			temp = temp->next;
		}
		return arr;
	}

	void Add(int data) override
	{
		AddToHead(data);
	}

	void Remove(int position)
	{
		DeleteByIndex(position);
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

