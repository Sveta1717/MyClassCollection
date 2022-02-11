#include "Library.h"
#include "MyCollection.h"
#include "DoublyLinkedList.h"
#include "SinglyLinkedList.h"
#include "Vector.h"
#include "Tree.h"


int main()
{
	MyCollection<int> m;
	cout << "____________________\n";
	m.Print();

	cout << "Class Vector\n";
	Vector v;
	cout << "Add:\n";
	v.Add(1);
	v.Add(2);
	v.Add(3);
	v.Print();
	cout << "Search 2: " << v.Search(2) << "\n";
	cout << "Sort\n";
	v.Sort();
	v.Print();
	cout << "Replace 5\n";
	v.Replace(5);
	v.Print();
	cout << "Remove 1\n";
	v.Remove(1);
	v.Print();

	cout << "\nClass SinglyLinkedList\n";
	SinglyLinkedList s;
	cout << "Add:\n";
	s.Add(1);
	s.Add(2);
	s.Add(3);
	s.Print();
	cout << "Search 2: " << s.Search(2) << "\n";
	cout << "Sort\n";
	s.Sort();
	s.Print();
	cout << "Replace 5\n";
	s.Replace(5);
	s.Print();
	cout << "Remove 1\n";
	s.Remove(1);
	s.Print();

	cout << "\nClass DoublyLinkedList\n";
	DoublyLinkedList d;
	cout << "Add:\n";
	d.Add(1);
	d.Add(2);
	d.Add(3);
	d.Print();
	cout << "Search 2: " << d.Search(2) << "\n";
	cout << "Sort\n";
	d.Sort();
	d.Print();
	cout << "Replace 5\n";
	d.Replace(5);
	d.Print();

	cout << "\nClass Tree\n";
	Tree t;
	cout << "Add:\n";
	t.Add(1);
	t.Add(2);
	t.Add(3);
	t.Print();
	cout << "Search 2: " << t.Search(2) << "\n";
	cout << "Replace 5\n";
	t.Replace(5);
	t.Print();
	cout << "Remove\n";
	s.Remove(1);
	s.Print();
}