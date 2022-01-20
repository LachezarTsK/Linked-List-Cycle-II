
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:

    ListNode* detectCycle(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return nullptr;
        }

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* meetingNode = nullptr;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow) {
                meetingNode = fast;
                break;
            }
        }

        slow = nullptr;
        fast = nullptr;
        delete fast, slow;

        return meetingNode == nullptr ? nullptr : findStartNodeOfCycle(head, meetingNode);
    }

    ListNode* findStartNodeOfCycle(ListNode* head, ListNode* meetingNode) {

        ListNode* current = head;
        while (current != meetingNode) {
            current = current->next;
            meetingNode = meetingNode->next;
        }
        current = nullptr;
        delete current;

        return meetingNode;
    }
};
