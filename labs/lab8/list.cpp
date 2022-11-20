#include "list.h"

namespace lab8 {

struct SingleLinkedList : List {
 private:
	// Inner type definitions
	struct Node {
		Node * next;
		int value;
	};

	// Properties declaration
	Node * head{};

	// Public interface implementation
 public:
	int size() const override {
		int size = 0;
		Node * current = head;
		while (current) {
			++size;
			current = current->next;
		}
		return size;
	}

	void push_front(int value) override {
		Node * current_head = this->head;
		Node * new_head = new Node{.next=current_head, .value=value};
		this->head = new_head;
	}

	int at(int index) const override {
		Node * current = this->head;
		for (int i = 0; i < index && current; ++i) {
			current = current->next;
		}
		return current->value;
	}

	void insert(int index, int value) override {
		if (index == 0) {
			push_front(value);
			return;
		}

		Node * previous = nullptr;
		Node * current = this->head;
		for (int i = 0; i < index; ++i) {
			if (!current) {
				return;
			}
			previous = current;
			current = current->next;
		}
		Node * inserted = new Node{.next=current, .value=value};
		previous->next = inserted;
	}

	void erase(int index) override {
		Node * current = head;
		if (index == 0) {
			if (!head) {
				return;
			}
			head = head->next;
			return;
		}

		Node * previous = nullptr;
		for (int i = 0; i < index; ++i) {
			if (!current) {
				return;
			}
			previous = current;
			current = current->next;
		}
		previous->next = current->next;
	}
};

List * new_single_linked_list() {
	return new SingleLinkedList{};
}

}