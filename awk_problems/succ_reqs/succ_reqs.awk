# YOUR CODE HERE
/^ptr/{
  if($5 < 0){
    print substr($3, 7, length($3) - 7) " 0"
  }
  else{
    print substr($3, 7, length($3) - 7) " 1"
  }
}
