#pragma once
#include <stdexcept>

template <typename ValueType>
class Container{
public:
	Container();
	~Container();
	void push_back(ValueType const & value);
	void push_front(ValueType const & value);
	void pop_back();
	void pop_front();
	const ValueType & operator[](unsigned int index) const;
	unsigned int size() const;
	bool is_empty() const;
	void free();
private:
	struct List{
		ValueType data;
		List * next;
	};
	List * elements;
	unsigned int count;
};

template <typename ValueType>
Container<ValueType>::Container(){
	count = 0;
	elements = NULL;
}

template <typename ValueType>
Container<ValueType>::~Container(){
	free();
}

template <typename ValueType>
void Container<ValueType>::push_back(ValueType const & value){
	List * last = new List;
	last->data = value;
	last->next = NULL;
	if (NULL == elements){
		elements = last;
	}
	else{
		List * tmp = elements;
		while (NULL != tmp->next){
			tmp = tmp->next;
		}
		tmp->next = last;
	}
	count++;
}

template <typename ValueType>
void Container<ValueType>::push_front(ValueType const & value){
	List * first = new List;
	first->data = value;
	first->next = elements;
	elements = first;
	count++;
}

template <typename ValueType>
void Container<ValueType>::pop_back(){
	if (0 == count){
		throw std::length_error("pop_back: Container is empty.");
	}
	List * last = elements;
	if (1 == count){
		delete elements->data;
		delete elements;
		elements = NULL;
	}
	while (NULL != last->next->next){
		last = last->next;
	}
	delete last->next;
	last->next = NULL;
	count--;
}

template <typename ValueType>
void Container<ValueType>::pop_front(){
	if (0 == count){
		throw std::length_error("pop_front: Container is empty.");
	}
	List * first = elements;
	elements = elements->next;
	delete first->data;
	delete first;
	count--;
}

template <typename ValueType>
const ValueType & Container<ValueType>::operator[](unsigned int index) const{
	if (index < 0 || index >= count){
		throw std::out_of_range("operator[]: out of range.");
	}
	List * current = elements;
	for (unsigned int i = 0; i<index; i++){
		current = current->next;
	}
	return current->data;
}

template <typename ValueType>
unsigned int Container<ValueType>::size() const{
	return count;
}

template <typename ValueType>
bool Container<ValueType>::is_empty() const{
	return bool(count);
}

template <typename ValueType>
void Container<ValueType>::free(){
	while (NULL != elements){
		pop_front();
	}
	count = 0;
}