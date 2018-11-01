# testMakeSQL
testMakeSQL is the test program for test the makesql dylib.
2018-11-01T11:59:58 added the possibility of up to four positional parameters: 
  1) leftmost positional parameter specifies the non-default prototype file [default = "/Users/cjc/sql/computeEnergyUsage.sql"]; 
  2) next positional parameter specifies the output file containing the resulting executable SQL [default = "/tmp/result.sql"];
  3) next positional parameter specifies the debug flag [default = '\0' which is interpreted as no debug data];
  4) the rightmost positional parameter specifies the number of vector entries [default = 5];
To override one of the positional parameters means that you will have to re-specify the default positional parameters of those positional parameters to the left of the positional parameter you wish to default override.

