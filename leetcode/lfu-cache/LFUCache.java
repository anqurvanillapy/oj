/**
 *  460. LFU Cache
 *
 *  Design and implement a data structure for Least Frequently Used (LFU) cache.
 *  It should support the following operations: get and put.
 *
 *  get(key) - Get the value (will always be positive) of the key if the key
 *  exists in the cache, otherwise return -1.
 *  put(key, value) - Set or insert the value if the key is not already present.
 *  When the cache reaches its capacity, it should invalidate the least
 *  frequently used item before inserting a new item. For the purpose of this
 *  problem, when there is a tie (i.e., two or more keys that have the same
 *  frequency), the least recently used key would be evicted.
 *
 *  - Follow up:
        + Could you do both operations in O(1) time complexity?
 */

import java.util.*;

public class LFUCache {
    private HashMap<Integer, Integer>   kvDB    = null;
    private HashMap<Integer, Node>      freqDB  = null;
    private Node head = null;
    private int capacity = 0;

    public LFUCache(int capacity) {
        kvDB    = new HashMap<Integer, Integer>();
        freqDB  = new HashMap<Integer, Node>();
        this.capacity = capacity;
    }

    public int get(int key) {
        if (kvDB.containsKey(key)) {
            incFrequency(key);
            return kvDB.get(key);
        }
        else {
            return -1;
        }
    }

    public void put(int key, int value) {
        if (capacity == 0) return;

        if (kvDB.containsKey(key)) {
            kvDB.put(key, value);
        } else {
            if (kvDB.size() < capacity) {
                kvDB.put(key, value);
            } else {
                removeLast();
                kvDB.put(key, value);
            }

            addKeyToHead(key);
        }

        incFrequency(key);
    }

    private void addKeyToHead(int key) {
        if (head == null) {
            head = new Node(0);
            head.keys.add(key);
        } else {
            if (head.frequency > 0) {
                // FIXME: It keeps adding a 0-frequency head
                Node _head = new Node(0);
                _head.keys.add(key);
                head.prev = _head;
                _head.next = head;
                head = _head;
            } else {    // the frequency is 0
                head.keys.add(key);
            }
        }

        freqDB.put(key, head);
    }

    private void incFrequency(int key) {
        Node node = freqDB.get(key);
        node.keys.remove(key);

        if (node.next == null) {
            node.next = new Node(node.frequency + 1);
            node.next.prev = node;
            node.next.keys.add(key);
        } else {
            if (node.frequency + 1 == node.next.frequency) {
                node.next.keys.add(key);
            } else {    // insert an intermediate node
                Node _node = new Node(node.frequency + 1);
                _node.keys.add(key);
                _node.prev = node;
                _node.next = node.next;
                node.next.prev = _node;
                node.next = _node;
            }
        }

        freqDB.put(key, node.next);
        // FIXME: It keeps deleting a 0-frequency head
        if (node.keys.isEmpty()) removeNode(node);
    }

    private void removeLast() {
        if (head == null) return;

        int last = 0;
        
        for (int n: head.keys) {
            last = n;   // the first element is least recently used
            break;
        }

        head.keys.remove(last);
        if (head.keys.isEmpty()) removeNode(head);
        freqDB.remove(last);
        kvDB.remove(last);
    }

    private void removeNode(Node node) {
        if (node.prev == null) {
            head = node.next;
        } else {
            node.prev.next = node.next;
        }

        if (node.next != null) node.next.prev = node.prev;
    }

    private class Node {
        public Node prev = null;
        public Node next = null;
        public LinkedHashSet<Integer> keys = null;
        public int frequency;

        private Node(int frequency) {
            keys = new LinkedHashSet<Integer>();
            this.frequency = frequency;
        }
    }
}
