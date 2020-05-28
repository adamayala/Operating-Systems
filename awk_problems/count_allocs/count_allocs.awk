# YOUR CODE HERE
/^ptr/{
  if($5 < 0){
    fail++
  }
  else{
    success++
  }
}
END {
  print "num successes: " success "; num failures: " fail
}
