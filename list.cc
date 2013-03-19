/*
 * list.cc
 */

#include <limits>
#include "list.h"
#include "debug.h"

/*
 * See debug.h for information on assert() and TRACE. Examples of use
 * are in the List destructor. Insert similar calls in other functions,
 * if you need them.
 *
 */

namespace cpp_lab1 {
    
    List::Node::Node(long v, Node* n) : value(v), next(n) {}
    
    List::List() : head(new Node) {}
    
    List::~List() {
        TRACE("List::~List()");
        assert(head != 0);
		
		Node* temp;
		while(head != 0) {
			temp = head;
			head = head->next;
			delete temp;
		}
	}
   
    void List::insert(long d) {
		/*
		 * head->next == 0 if list is empty
		 * Right hand side evaluates before assignment to left hand side
		 * head->next is the first object in the list, head is the empty help node
		 */
		head->next = new Node(d, head->next);

    }
    
   void List::remove(long d, DeleteFlag df) {
	
	   Node* iter = head;
		// Each loop checks if the NEXT value exists and if it matches the criteria for deletion
		// 
		switch ( df ) {
			case List::EQUAL :
				while (iter->next != 0 && iter->next->value != d) {
					iter = iter->next;
				}
			break;
			case List::LESS :
				while (iter->next != 0 && iter->next->value >= d) {
					iter = iter->next;
				}
			break;
			
			case List::GREATER :
				while (iter->next != 0 && iter->next->value <= d) {
					iter = iter->next;
				}
			break;
		}
		
		if (iter->next != 0) { // If we actually FOUND an object to delete, do so!
			Node* temp = iter->next->next;
			delete iter->next;
			iter->next = temp;
		} else {
			std::cout << "Could not match an item to remove." << std::endl;
		}
	}
    
    int List::size() const {
        int size = 0;
        for (Node* iter = head->next; iter != 0; iter = iter->next) {
            ++size;
        }
        return size;
    }
    
    bool List::empty() const {
        if (head->next != 0)
			return false;
		else
		return true;
    }
    
    long List::largest() const {
        long largest = std::numeric_limits<long>::min();
		for (Node* iter = head->next; iter != 0; iter = iter->next) {
            if (iter->value > largest) {
				largest = iter->value;
			}
        }
        return largest;
    }
    
    void List::debugPrint() const {
#ifndef NDEBUG
        //-----------------------------------------------------------------
        // debugPrint() is used only during development, so we enclose the
        // code in this #ifndef block. The code will be removed when NDEBUG 
        // is defined.
        //
        // NDEBUG should be defined when compiling production release
        // versions. Use the -DNDEBUG option on the compiler command line.
        //-----------------------------------------------------------------
        for (Node* iter = head->next; iter != 0; iter = iter->next) {
            std::cout << iter->value << " ";
        }
        std::cout << std::endl;
#endif
    }
}

