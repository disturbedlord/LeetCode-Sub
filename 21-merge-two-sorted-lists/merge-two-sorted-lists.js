/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var mergeTwoLists = function(l1, l2) {
    
    var result = new ListNode(-1 , null);
    var dummy = result;
    
    while(l1 !== null && l2 !== null){
        if(l1.val < l2.val){
            result.next = new ListNode(l1.val , null);
            l1 = l1.next;
            result = result.next;
        }else if(l1.val > l2.val){
            result.next = new ListNode(l2.val , null);
            l2 = l2.next;
            result = result.next;
        }else{
            result.next = new ListNode(l1.val , null);
            l1 = l1.next;
            result = result.next;
            result.next = new ListNode(l2.val , null);
            l2 = l2.next;
            result = result.next;
        }
    }
    
    while(l1 !== null){
        result.next = new ListNode(l1.val , null);
        l1 = l1.next;
        result = result.next;
    }
    
    
    while(l2 !== null){
        result.next = new ListNode(l2.val , null);
        l2 = l2.next;
        result = result.next;
    }
    
    return dummy.next;
};