# YOUR CODE HERE
/^Free List/{
  n = $5
  for (i = 0; i < n; i++){
    printf("%d ", substr($(9 + (4 * i)), 4))
  }
  printf("\n")
}
