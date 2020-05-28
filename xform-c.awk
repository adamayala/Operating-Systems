
# YOUR CODE HERE
{ FS = ","}
/^Ident/ 
{
  print $1 print $2 print $3 "something" 
}
