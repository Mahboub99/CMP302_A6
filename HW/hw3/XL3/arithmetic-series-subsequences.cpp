#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <functional>
#include <random>
#include <set>

using std::cin;
using std::cout;
using std::endl;
using u64 = unsigned long long;
using vec = std::vector<int>;
using sti = std::set<int>;
using mpi = std::unordered_map<int, int>;

enum SEQ {
  UNSEQUENCED = -1,
  FAILED = -2,
  TERMINATING = -3,
};

vec make_sequence(const vec &numbers,  const int DIFFERENCE) {
  vec sequence(numbers.size(), UNSEQUENCED);
  int countVisited = 0;
  while (countVisited < numbers.size()) {
    int current = -1;

    for (int i = 0; i < numbers.size(); i++) {
      // Empty sequence and unsequenced number
      if (current < 0) {
        if (sequence[i] == UNSEQUENCED) {
          current = i;
          sequence[current] = FAILED;
        }
        continue;
      }

      // If the number is sequenced, break
      if (sequence[current] > 0) break;

      // Found an element that can be sequenced
      if (numbers[i] == numbers[current] || numbers[i] - DIFFERENCE == numbers[current]) {
        sequence[current] = i;
        current = i;
        countVisited++;
      }
    }
    switch (sequence[current]) {
    case UNSEQUENCED:
    case FAILED:
      sequence[current] = TERMINATING;
      countVisited++;
    }
  }
  return sequence;
}

u64 solve(const vec &numbers, std::unordered_map<int, sti> &indices, int DIFFERENCE, const int SEQUENCE_LENGTH) {
  sti startedAt;
  vec sequence = make_sequence(numbers, DIFFERENCE);

  std::function<u64(int, int)> walk_sequence = [&](int start, int length) -> u64 {
    // Completed sequence
    if (length == SEQUENCE_LENGTH) return 1;

    // Failed sequence
    if (start == TERMINATING) return 0;
    
    // First element
    if (!length) startedAt.insert(start);

    u64 repetitions = 1;
    u64 total = 0;
    int x = numbers[start];
    int current = start;
    int next = sequence[current];

    while (next != TERMINATING) {
      // Repetition
      if (numbers[next] == x) {
        repetitions++;

        // First element
        if (!length) startedAt.insert(next);
      }
      
      // Walk to the next occurence if possible
      else {
        auto itr = indices[x].upper_bound(current);
        int skip = itr == indices[x].end() ? TERMINATING : *itr;

        total += walk_sequence(skip, length);
        break;
      }

      current = next;
      next = sequence[current];
    }

    // Advance
    total += repetitions * walk_sequence(next, length+1);
    return total;
  };

  u64 answer = 0;
  for (int i = 0; i < sequence.size(); i++) {
    if (startedAt.count(i)) continue;
    answer += walk_sequence(i, 0);
  }
  return answer;
}

int main() {
  int N, D, M;
  cin >> N >> D >> M;
  std::unordered_map<int, sti> indices;

  vec numbers(N);
  for (int i = 0; i < numbers.size(); i++) {
    cin >> numbers[i];
    indices[numbers[i]].insert(i);
  }

  u64 answer = solve(numbers, indices, D, M);
  cout << answer;
  return 0;
}