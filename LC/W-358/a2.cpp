#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rev(ListNode* head){
        ListNode* prev = NULL, *next = NULL;
        ListNode* curr = head;
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    ListNode* doubleIt(ListNode* head) {
        head = rev(head);
        ListNode* root = new ListNode(-1);
        ListNode* temp1 = root;
        int carry = 0;
        ListNode* temp = head;
        while(temp){
            int val = (temp->val*2);
            val = val + carry;
            carry = val/10;
            val = val % 10;
            temp1->next = new ListNode(val);

            temp = temp->next;
            temp1 = temp1->next;
        }

        while(carry){
            temp1->next = new ListNode(carry);
            carry = carry/10;
        }

        return rev(root->next);
    }
};