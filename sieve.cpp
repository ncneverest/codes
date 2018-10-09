#define SIZE int(5e6)

bool primes[SIZE];

void sieve() {
	for ( int i = 0; i < SIZE; i ++ ) primes[i] = true;
	for ( int i = 2; i < SIZE; i ++ ) {
		if ( !primes[i] ) continue;
		for ( int j = 2 * i; j < SIZE; j += i ) primes[j] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	sieve();
	return 0;
}
