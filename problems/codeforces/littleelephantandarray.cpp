#include <cstdio>
#include <algorithm>
using namespace std;

#define N 311111
#define A 1111111
#define BLOCK 555

int cnt[A], a[N], ans[N], answer = 0;

struct node {
	int L, R, i;
}q[N];


bool cmp(node x, node y) {
    if(x.L/BLOCK != y.L/BLOCK)
        return x.L/BLOCK < y.L/BLOCK;

    return x.R < y.R;
}

void add(int position) {
    if(a[position] >= N) return;

    cnt[a[position]]++;
    if(cnt[a[position]] == a[position])
        answer++;
 	else if (cnt[a[position]] == a[position] + 1) answer--;
}

void remove(int position) {
    if(a[position] >= N) return;

	cnt[a[position]]--;
 	if(cnt[a[position]] == a[position] - 1)
 		answer--;
    else if (cnt[a[position]] == a[position]) answer++;
}

int main() {
	int n, m;
 	scanf("%d %d", &n, &m);
	for(int i=0; i<n; i++)
 		scanf("%d", &a[i]);

 	for(int i = 0; i < m; i++) {
 		scanf("%d %d", &q[i].L, &q[i].R);
 		q[i].L--; q[i].R--;
 		q[i].i = i;
	}


 	sort(q, q + m, cmp);


 	int currentL = 0, currentR = 0;
 	for(int i = 0; i < m; i++) {
 		int L = q[i].L, R = q[i].R;
 		while(currentL < L) {
 			remove(currentL);
 			currentL++;
 		}
 		while(currentL > L) {
			add(currentL-1);
 			currentL--;
 		}
		while(currentR <= R) {
 			add(currentR);
 			currentR++;
 		}
 		while(currentR > R+1) {
 			remove(currentR-1);
			currentR--;
 		}
 		ans[q[i].i] = answer;
 	}


 	for(int i = 0; i < m; i++)
 		printf("%d\n", ans[i]);
}
