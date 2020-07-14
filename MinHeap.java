class MinHeap{
	private int size;
	private int maxSize = 1024;
	private int[] elem;

	public MinHeap(int size){
		this.maxSize = size;
		this.size = 0;
		this.elem = new int[size+1];
	}

	public int getMin(){
		if(this.size == 0){
			System.out.println("The heap is empty.");
			return -1;
		}
		return this.elem[1];
	}

	public void insert(int n){
		if(this.size == this.maxSize)
			System.out.println("The heap has reached its maximum capacity.");
		else{
			this.elem[this.size+1] = n;
			this.size ++;
			int pos = this.size;
			while(this.elem[pos]<this.elem[pos/2]){
				int t = this.elem[pos];
				this.elem[pos] = this.elem[pos/2];
				this.elem[pos/2] = t;
				pos = pos/2;
			}
		}
	}

	public void eraseMin(){
		if(this.size == 0){
			System.out.println("The heap is empty.");
		}

		this.elem[1] = this.elem[this.size];
		this.size --;
		int pos = 1;
		int a, b, c, t;
		while(pos*2 <= size){
			if(pos*2+1<=size){
				a = pos;
				b = pos*2;
				c = pos*2+1;
				if(this.elem[a]>this.elem[b] && this.elem[a]>this.elem[c]){
					if(this.elem[b]>this.elem[c]){
						t = this.elem[a];
						this.elem[a] = this.elem[c];
						this.elem[c] = t;
						pos = c;
					}
					else{
						t = this.elem[a];
						this.elem[a] = this.elem[b];
						this.elem[b] = t;
						pos = b;
					}
				}
				else if(this.elem[a]>this.elem[b]){
					t = this.elem[a];
					this.elem[a] = this.elem[b];
					this.elem[b] = t;
					pos = b;
				}
				else if(this.elem[a]>this.elem[c]){
					t = this.elem[a];
					this.elem[a] = this.elem[c];
					this.elem[c] = t;
					pos = c;
				}
			}
			else{
				a = pos;
				b = pos*2;
				if(this.elem[a]>this.elem[b]){
					t = this.elem[a];
					this.elem[a] = this.elem[b];
					this.elem[b] = t;
				}
				pos = b;
			}
		}
		
	}

	public void display(){
			for (int i =1;i<= this.size;i++)
				System.out.println(this.elem[i]);
		}


	public static void main(String[] args){
		MinHeap heap = new MinHeap(10);
		heap.insert(2);
		heap.insert(5);
		heap.insert(1);
		heap.insert(3);
		heap.insert(4);

		heap.display();

		heap.eraseMin();
		heap.eraseMin(); 
		heap.eraseMin();
		heap.eraseMin();
		heap.eraseMin();
		heap.eraseMin();

		heap.display();
	}
}