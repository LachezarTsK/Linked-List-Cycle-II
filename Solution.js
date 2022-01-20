
/**
 'function ListNode' here is included only for information.
 *It is defined internally on leetcode.com and should 
 *not be included in the code when running it on the website.
 *
 * @param {number} val
 */
function ListNode(val) {
    this.val = val;
    this.next = null;
}

/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var detectCycle = function (head) {

    if (head === null || head.next === null) {
        return null;
    }

    let slow = head;
    let fast = head;
    let meetingNode = null;

    while (fast !== null && fast.next !== null) {
        slow = slow.next;
        fast = fast.next.next;
        if (fast === slow) {
            meetingNode = fast;
            break;
        }
    }

    return meetingNode === null ? null : findStartNodeOfCycle(head, meetingNode);
};

/**
 * @param {ListNode} head
 * @param {ListNode} meetingNode
 * @return {ListNode}
 */
function findStartNodeOfCycle(head, meetingNode) {
    let current = head;
    while (current !== meetingNode) {
        current = current.next;
        meetingNode = meetingNode.next;
    }
    return meetingNode;
}
