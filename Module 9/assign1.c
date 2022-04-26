// Don't ask what this does
#include <stdio.h>

int main() {
  int num_seats, num_votes, num_lists;
  int quota, idx_list, vote, seat;
  printf("Total number of seats: ");
  scanf("%d", &num_seats);
  printf("Total number of votes: ");
  scanf("%d", &num_votes);
  printf("Total number of lists: ");
  scanf("%d", &num_lists);
  quota = num_votes / num_seats;
  idx_list = 1;
  while (idx_list <= num_lists) {
    printf("Votes for list %d: ", idx_list);
    scanf("%d", &vote);
    printf("Automatic seat for list %d: ", idx_list);
    seat = vote / quota;
    printf("%d\n", seat);
    printf("Remainder for list %d: ", idx_list);
    printf("%d\n", vote - seat * quota);
    idx_list++;
  }
  return 0;
}