#!/usr/bin/awk -f
# return average length of line in input file

# YOUR CODE HERE
{
  if(length($0) != 0){
    total += length($0)
    numLines++
  }
}
END {
  print int(total / numLines)
}
