# C:\MATLAB\R2009b\sys\perl\win32\bin\perl.exe extractCol.pl

use Getopt::Long;
use strict;       #keeps variables local - declared as my(var) then cnan be used as var afterwards

 GetOptions(
     "opt1:s"    => \my $opt1,
#     "opt2:s"    => \my $opt2,
#     "opt3:s"    => \my $opt3,
#     "opt4:s"    => \my $opt4,
 );

print "args is $opt1\n";

my($inputfile) = $opt1 . ".txt";
my($outputfile) =$opt1 . '.def';

open (data, "$inputfile");

open(dataout, ">$outputfile"); 

print dataout "EXPORTS\n";

my($counter)=0;

while (<data>) {
    #chomp; #removes newline character
    if($counter<287){ # 19 for first bit of text or 287 to include functions starting with ?
	# do nothing
    }elsif ($counter>1282){
	# do nothing
	}else{

    my($col1)= substr $_, 0, 26;     # extract the field
    my($col2) = substr $_, 26;    # from 26 to the end
	
	substr( $_, 0, 26 ) = ""; # to delete
    
    print dataout "$col2\n"; # output data to file
    }
  $counter=$counter+1;
}
print "Finished processing.\n";
close (data);

close (dataout);





# You can use "split" if the columns are separated by whitespace or some
# other delimiter, as long as whitespace or the delimiter cannot appear as
# part of the data.

# my $line = ' fred barney betty ';
# my @columns = split /\s+/, $line;
# # ( '', 'fred', 'barney', 'betty' );

# my $line = 'fred||barney||betty';
# my @columns = split /\|/, $line;
# # ( 'fred', '', 'barney', '', 'betty' );













