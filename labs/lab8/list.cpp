#include "list.h"
#include <memory>

namespace lab8 {

struct SingleLinkedList : List {
 private:
	// Inner type definitions
	struct Node {
		std::shared_ptr<Node> next;
		int value;
	};

	// Properties declaration
	std::shared_ptr<Node> head{};

	// Public interface implementation
 public:
	int size() const override {
		int size = 0;
		std::shared_ptr<Node> current = head;
		while (current) {
			++size;
			current = current->next;
		}
		return size;
	}

	void push_front(int value) override {
		std::shared_ptr<Node> current_head = this->head;
		std::shared_ptr<Node> new_head = std::make_shared<Node>();
		new_head->next = current_head;
		new_head->value = value;
		this->head = new_head;
	}

	int at(int index) const override {
		std::shared_ptr<Node> current = this->head;
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

		std::shared_ptr<Node> previous = nullptr;
		std::shared_ptr<Node> current = this->head;
		for (int i = 0; i < index; ++i) {
			if (!current) {
				return;
			}
			previous = current;
			current = current->next;
		}
		std::shared_ptr<Node> inserted = std::make_shared<Node>();
		inserted->next = current;
		inserted->value = value;
		previous->next = inserted;
	}

	void erase(int index) override {
		std::shared_ptr<Node> current = head;
		if (index == 0) {
			if (!head) {
				return;
			}
			head = head->next;
			return;
		}

		std::shared_ptr<Node> previous = nullptr;
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
