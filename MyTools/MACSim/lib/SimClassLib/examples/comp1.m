%% Compile from library
%mex sim_example1.cpp -I../code/include ../code/bin/sim.lib -v

%% Compile from library with setup mexopts.bat
%mex sim_example1.cpp sim.lib -v

%% Compile from source
mex sim_example1.cpp ../code/src/sim_functions.cpp ../code/src/sim_class.cpp ../code/src/sim_interface_container.cpp ../code/src/sim_interface.cpp ../code/src/sim_exception.cpp ../code/src/sim_vector.cpp ../../MatrixClassLib/code/src/matrix.cpp ../../MatrixClassLib/code/src/matrix_access.cpp ../../MatrixClassLib/code/src/matrix_operator.cpp -v