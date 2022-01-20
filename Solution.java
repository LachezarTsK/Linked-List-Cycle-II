
public class Solution {

    public ListNode detectCycle(ListNode head) {

        if (head == null || head.next == null) {
            return null;
        }

        ListNode slow = head;
        ListNode fast = head;
        ListNode meetingNode = null;

        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
            if (fast == slow) {
                meetingNode = fast;
                break;
            }
        }

        return meetingNode == null ? null : findStartNodeOfCycle(head, meetingNode);
    }

    public ListNode findStartNodeOfCycle(ListNode head, ListNode meetingNode) {
        ListNode current = head;
        while (current != meetingNode) {
            current = current.next;
            meetingNode = meetingNode.next;
        }
        return meetingNode;
    }
}

class ListNode {

    int val;
    ListNode next;

    ListNode(int x) {
        val = x;
        next = null;
    }
}
