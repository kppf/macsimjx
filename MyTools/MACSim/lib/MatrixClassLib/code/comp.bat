bcc32  -c -3 -P- -w- -pc -a8 -I"c:\Program Files\Borland\BCC55\INCLUDE" -DMATLAB_MEX_FILE -ohx_sim.obj -I"C:\Program Files\MATLABR11"\extern\include -I"C:\Program Files\MATLABR11"\simulink\include -O2 example.cpp src/matrix.cpp src/matrix_operator.cpp src/matrix_access.cpp ../../SimClassLib/code/src/sim_vector.cpp