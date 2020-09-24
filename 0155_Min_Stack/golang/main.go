type MinStack struct {
	st     []int
	min_st []int
}

/** initialize your data structure here. */
func Constructor() MinStack {
	s := MinStack{}
	s.st = []int{}
	s.min_st = []int{}
	return s
}

func (this *MinStack) Push(x int) {
	this.st = append(this.st, x)
	min_n := len(this.min_st)
	if min_n == 0 || x <= this.min_st[min_n-1] {
		this.min_st = append(this.min_st, x)
	}
}

func (this *MinStack) Pop() {
	n := len(this.st)
	min_n := len(this.min_st)
	if this.st[n-1] == this.min_st[min_n-1] {
		this.min_st = this.min_st[:min_n-1]
	}
	this.st = this.st[:n-1]
}

func (this *MinStack) Top() int {
	n := len(this.st)
	if n == 0 {
		return 0
	}
	return this.st[n-1]
}

func (this *MinStack) GetMin() int {
	min_n := len(this.min_st)
	return this.min_st[min_n-1]
}

/**
 * Your MinStack object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Push(x);
 * obj.Pop();
 * param_3 := obj.Top();
 * param_4 := obj.GetMin();
 */