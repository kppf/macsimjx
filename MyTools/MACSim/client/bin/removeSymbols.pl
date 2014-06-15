# C:\MATLAB\R2009b\sys\perl\win32\bin\perl.exe removeSymbols.pl
# This script removes the decorative symbols to allow recompikation by another compiler.

use Getopt::Long;
use strict;       #keeps variables local - declared as my(var) then can be used as $var afterwards

 GetOptions(
     "opt1:s"    => \my $opt1,
#     "opt2:s"    => \my $opt2,
#     "opt3:s"    => \my $opt3,
#     "opt4:s"    => \my $opt4,
 );

print "args is $opt1\n";

my($datafile) = $opt1 . ".def";
my($tempfile) = "temp.def";

open (data, "$datafile")     or die "can't open $datafile: $!";
open (tempdata, ">$tempfile") or die "can't open or create $tempfile: $!";

print tempdata "EXPORTS\n";

my($counter)=0;

while (<data>) {
    #chomp; #removes newline character
	if(($counter==0)&&($_ !~ /LIBRARY/)){
	die "Expected LIBRARY at start of file to indicate a borland generated .diff file. Exiting.\n";
	}
    if($counter<271){ 
	# do nothing
	}else{  
    print tempdata "$_"; # output data to file
    }
  $counter=$counter+1;
}


close (data);
unlink($opt1 . ".def");


close (tempdata);

rename($tempfile, $datafile);


print "Finished processing.\n";


















