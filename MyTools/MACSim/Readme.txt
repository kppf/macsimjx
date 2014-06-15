Running a simple example of MACSim (readme by C. Robinson)

Ensure javac and bcc32(freely available from borland) are set up as environmental variables.
Also a recent version of Simulink is needed.
Copy MACSim folder to C:\Code  (or a directory of your choice, but amend the following instructions)

At command prompt type:

cd C:\Code\MACSim\jserver\bin   
make
cd C:\Code\MACSim\jserver\examples\simple
make
run

(Server is now running.)

Now, in Simulink, navigate to "cd C:\MyTools\MACSim\jserver\examples\simple" and 
double click the simulink model file "simple.mdl" and run it.   Output should appear on the scope.
(A warning message appears about inconsistent sample times - but can be ignored).

Examine C:\Code\MACSim\jserver\examples\simple.java to see how it works.

N.B. In this version of MACSim, the server coded to run for C-coded programs  (in folder server) doesn't work 
(Peter Mendham has a working one though).