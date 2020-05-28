#!/usr/bin/awk -f
# for *every* problem ID in input, give number of incorrect (non-0) answers

# YOUR CODE HERE
BEGIN{ FS="," };
{

  if($3 == 0 && $3 != "score" )
    cnt[$2] = cnt[$2] + 0
  else if($3 != "score"){
    cnt[$2]++
  }
}
END {
  print("prob_id,num_missed")
  
  for(prob in cnt){
    print prob","cnt[prob]
  }
}
