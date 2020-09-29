type node struct {
	key, value int
	prev, next *node
}

type LRUCache struct {
	head *node
	mMap map[int]*node
}

func (this *LRUCache) move2Head(n *node) {
	if n == this.head {
		this.head = this.head.prev
		return
	}
	n.next.prev = n.prev
	n.prev.next = n.next

	head := this.head
	n.next = head.next
	n.next.prev = n
	n.prev = head
	head.next = n
}

func Constructor(capacity int) LRUCache {
	lru := LRUCache{}
	lru.mMap = make(map[int]*node)
	lru.head = &node{-1, -1, nil, nil}

	p := lru.head
	for i := 1; i < capacity; i++ {
		p.next = &node{-1, -1, p, nil}
		p = p.next
	}
	p.next = lru.head
	lru.head.prev = p
	return lru
}

func (this *LRUCache) Get(key int) int {
	n, ok := this.mMap[key]
	if ok {
		this.move2Head(n)
		return n.value
	}
	return -1
}

func (this *LRUCache) Put(key int, value int) {
	n, ok := this.mMap[key]
	if ok == false {
		delete(this.mMap, this.head.key)
		this.head.key = key
		this.head.value = value
		this.mMap[key] = this.head
		this.head = this.head.prev
	} else {
		n.value = value
		this.move2Head(n)
	}
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * obj := Constructor(capacity);
 * param_1 := obj.Get(key);
 * obj.Put(key,value);
 */