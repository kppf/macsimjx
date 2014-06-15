<?xml version='1.0' encoding='ISO-8859-1' standalone='yes'?>
<tagfile>
  <compound kind="page">
    <name>index</name>
    <title>The Sim Class Library</title>
    <filename>index</filename>
    <docanchor>inher_define</docanchor>
    <docanchor>Introduction</docanchor>
    <docanchor>memb_funcs</docanchor>
    <docanchor>installation</docanchor>
    <docanchor>ios</docanchor>
    <docanchor>Compilation</docanchor>
    <docanchor>matlab5</docanchor>
    <docanchor>Usage</docanchor>
  </compound>
  <compound kind="file">
    <name>sim.h</name>
    <path>C:/ltn100/Shared/SimClassLib/code/include/</path>
    <filename>sim_8h</filename>
    <includes id="sim__class_8h" name="sim_class.h" local="yes">sim_class.h</includes>
    <includes id="sim__interface__container_8h" name="sim_interface_container.h" local="yes">sim_interface_container.h</includes>
    <includes id="sim__interface_8h" name="sim_interface.h" local="yes">sim_interface.h</includes>
    <includes id="sim__exception_8h" name="sim_exception.h" local="yes">sim_exception.h</includes>
    <includes id="sim__functions_8h" name="sim_functions.h" local="yes">sim_functions.h</includes>
    <includes id="sim__vector_8h" name="sim_vector.h" local="yes">sim_vector.h</includes>
    <member kind="function">
      <type>Sim *</type>
      <name>createSim</name>
      <anchor>a0</anchor>
      <arglist>(SimStruct *S)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>sim_class.h</name>
    <path>C:/ltn100/Shared/SimClassLib/code/include/</path>
    <filename>sim__class_8h</filename>
    <includes id="sim__interface__container_8h" name="sim_interface_container.h" local="yes">sim_interface_container.h</includes>
    <class kind="class">Sim</class>
  </compound>
  <compound kind="file">
    <name>sim_exception.h</name>
    <path>C:/ltn100/Shared/SimClassLib/code/include/</path>
    <filename>sim__exception_8h</filename>
    <includes id="sim_8h" name="sim.h" local="yes">sim.h</includes>
    <class kind="class">Exception</class>
  </compound>
  <compound kind="file">
    <name>sim_functions.h</name>
    <path>C:/ltn100/Shared/SimClassLib/code/include/</path>
    <filename>sim__functions_8h</filename>
    <member kind="function">
      <type>void</type>
      <name>SimInitializeSizes</name>
      <anchor>a0</anchor>
      <arglist>(SimStruct *S, Sim *sim_temp)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>SimInitializeSampleTimes</name>
      <anchor>a1</anchor>
      <arglist>(SimStruct *S)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>SimStart</name>
      <anchor>a2</anchor>
      <arglist>(SimStruct *S)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>SimInitializeConditions</name>
      <anchor>a3</anchor>
      <arglist>(SimStruct *S)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>SimUpdate</name>
      <anchor>a4</anchor>
      <arglist>(SimStruct *S, int_T tid)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>SimDerivatives</name>
      <anchor>a5</anchor>
      <arglist>(SimStruct *S)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>SimOutputs</name>
      <anchor>a6</anchor>
      <arglist>(SimStruct *S, int_T tid)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>SimTerminate</name>
      <anchor>a7</anchor>
      <arglist>(SimStruct *S)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>sim_interface.h</name>
    <path>C:/ltn100/Shared/SimClassLib/code/include/</path>
    <filename>sim__interface_8h</filename>
    <includes id="sim__vector_8h" name="sim_vector.h" local="yes">sim_vector.h</includes>
    <class kind="class">Interface</class>
    <class kind="class">ContinuousInterface</class>
    <class kind="class">DiscreteInterface</class>
  </compound>
  <compound kind="file">
    <name>sim_interface_container.h</name>
    <path>C:/ltn100/Shared/SimClassLib/code/include/</path>
    <filename>sim__interface__container_8h</filename>
    <includes id="sim__interface_8h" name="sim_interface.h" local="yes">sim_interface.h</includes>
    <class kind="class">InterfaceContainer</class>
  </compound>
  <compound kind="file">
    <name>sim_vector.h</name>
    <path>C:/ltn100/Shared/SimClassLib/code/include/</path>
    <filename>sim__vector_8h</filename>
    <class kind="class">SimVectorReadAccess</class>
    <class kind="class">SimInputVectorReadAccess</class>
    <class kind="class">SimVectorWriteAccess</class>
    <class kind="class">SimVectorConstant</class>
    <class kind="class">SimVector</class>
    <class kind="class">SimInputVector</class>
    <class kind="class">SimParamVector</class>
    <class kind="class">SimOutputVector</class>
    <class kind="class">SimContinuousStateVector</class>
    <class kind="class">SimDiscreteStateVector</class>
    <class kind="class">SimStateDerivativeVector</class>
  </compound>
  <compound kind="file">
    <name>sim_class.cpp</name>
    <path>C:/ltn100/Shared/SimClassLib/code/src/</path>
    <filename>sim__class_8cpp</filename>
    <includes id="sim__class_8h" name="sim_class.h" local="yes">../include/sim_class.h</includes>
  </compound>
  <compound kind="file">
    <name>sim_exception.cpp</name>
    <path>C:/ltn100/Shared/SimClassLib/code/src/</path>
    <filename>sim__exception_8cpp</filename>
    <includes id="sim__exception_8h" name="sim_exception.h" local="yes">../include/sim_exception.h</includes>
    <includes id="sim_8h" name="sim.h" local="yes">../include/sim.h</includes>
  </compound>
  <compound kind="file">
    <name>sim_functions.cpp</name>
    <path>C:/ltn100/Shared/SimClassLib/code/src/</path>
    <filename>sim__functions_8cpp</filename>
    <includes id="sim_8h" name="sim.h" local="yes">../include/sim.h</includes>
    <member kind="define">
      <type>#define</type>
      <name>Sim_START</name>
      <anchor>a0</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>Sim_INITIALIZE_CONDITIONS</name>
      <anchor>a1</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>Sim_UPDATE</name>
      <anchor>a2</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>Sim_DERIVATIVES</name>
      <anchor>a3</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>SimInitializeSizes</name>
      <anchor>a4</anchor>
      <arglist>(SimStruct *S, Sim *sim_temp)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>SimInitializeSampleTimes</name>
      <anchor>a5</anchor>
      <arglist>(SimStruct *S)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>SimStart</name>
      <anchor>a6</anchor>
      <arglist>(SimStruct *S)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>SimInitializeConditions</name>
      <anchor>a7</anchor>
      <arglist>(SimStruct *S)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>SimUpdate</name>
      <anchor>a8</anchor>
      <arglist>(SimStruct *S, int_T tid)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>SimDerivatives</name>
      <anchor>a9</anchor>
      <arglist>(SimStruct *S)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>SimOutputs</name>
      <anchor>a10</anchor>
      <arglist>(SimStruct *S, int_T tid)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>SimTerminate</name>
      <anchor>a11</anchor>
      <arglist>(SimStruct *S)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>sim_interface.cpp</name>
    <path>C:/ltn100/Shared/SimClassLib/code/src/</path>
    <filename>sim__interface_8cpp</filename>
    <includes id="sim__interface_8h" name="sim_interface.h" local="yes">../include/sim_interface.h</includes>
    <includes id="sim__class_8h" name="sim_class.h" local="yes">../include/sim_class.h</includes>
    <includes id="sim__exception_8h" name="sim_exception.h" local="yes">../include/sim_exception.h</includes>
  </compound>
  <compound kind="file">
    <name>sim_interface_container.cpp</name>
    <path>C:/ltn100/Shared/SimClassLib/code/src/</path>
    <filename>sim__interface__container_8cpp</filename>
    <includes id="sim__interface__container_8h" name="sim_interface_container.h" local="yes">../include/sim_interface_container.h</includes>
    <includes id="sim__interface_8h" name="sim_interface.h" local="yes">../include/sim_interface.h</includes>
    <includes id="sim__exception_8h" name="sim_exception.h" local="yes">../include/sim_exception.h</includes>
    <includes id="sim__class_8h" name="sim_class.h" local="yes">../include/sim_class.h</includes>
  </compound>
  <compound kind="file">
    <name>sim_vector.cpp</name>
    <path>C:/ltn100/Shared/SimClassLib/code/src/</path>
    <filename>sim__vector_8cpp</filename>
    <includes id="sim__vector_8h" name="sim_vector.h" local="yes">../include/sim_vector.h</includes>
    <includes id="sim__interface__container_8h" name="sim_interface_container.h" local="yes">../include/sim_interface_container.h</includes>
    <includes id="sim__interface_8h" name="sim_interface.h" local="yes">../include/sim_interface.h</includes>
  </compound>
  <compound kind="class">
    <name>ContinuousInterface</name>
    <filename>class_continuous_interface.html</filename>
    <base>Interface</base>
    <member kind="function">
      <type></type>
      <name>ContinuousInterface</name>
      <anchor>a0</anchor>
      <arglist>(InterfaceContainer *p_interfaceContainer, const char *p_name, const unsigned int p_inputs, const unsigned int p_outputs, const unsigned int p_states, const unsigned int p_params)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual unsigned int</type>
      <name>getNumStates</name>
      <anchor>a1</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>invalidateX</name>
      <anchor>a2</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>invalidateDx</name>
      <anchor>a3</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable">
      <type>SimStateDerivativeVector</type>
      <name>dx</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>SimContinuousStateVector</type>
      <name>x</name>
      <anchor>o1</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>DiscreteInterface</name>
    <filename>class_discrete_interface.html</filename>
    <base>Interface</base>
    <member kind="function">
      <type></type>
      <name>DiscreteInterface</name>
      <anchor>a0</anchor>
      <arglist>(InterfaceContainer *p_interfaceContainer, const char *p_name, const unsigned int p_inputs, const unsigned int p_outputs, const unsigned int p_states, const unsigned int p_params, const double p_inputSampleTime, const double p_outputSampleTime, const double p_inputSampleOffset, const double p_outputSampleOffset)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>DiscreteInterface</name>
      <anchor>a1</anchor>
      <arglist>(InterfaceContainer *p_interfaceContainer, const char *p_name, const unsigned int p_inputs, const unsigned int p_outputs, const unsigned int p_states, const unsigned int p_params, const double p_sampleTime)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual unsigned int</type>
      <name>getNumStates</name>
      <anchor>a2</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>invalidateX</name>
      <anchor>a3</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>getInputSampleTime</name>
      <anchor>a4</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>getInputSampleOffset</name>
      <anchor>a5</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>getOutputSampleTime</name>
      <anchor>a6</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>getOutputSampleOffset</name>
      <anchor>a7</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="variable">
      <type>SimDiscreteStateVector</type>
      <name>x</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>double</type>
      <name>m_inputSampleTime</name>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>double</type>
      <name>m_inputSampleOffset</name>
      <anchor>p1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>double</type>
      <name>m_outputSampleTime</name>
      <anchor>p2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>double</type>
      <name>m_outputSampleOffset</name>
      <anchor>p3</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Exception</name>
    <filename>class_exception.html</filename>
    <member kind="function">
      <type></type>
      <name>Exception</name>
      <anchor>a0</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>Exception</name>
      <anchor>a1</anchor>
      <arglist>(const char *p_string)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>kill</name>
      <anchor>a2</anchor>
      <arglist>(SimStruct *p_S)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>string</type>
      <name>m_exception_name</name>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Interface</name>
    <filename>class_interface.html</filename>
    <member kind="function">
      <type></type>
      <name>Interface</name>
      <anchor>a0</anchor>
      <arglist>(InterfaceContainer *p_interfaceContainer, const char *p_name, const unsigned int p_inputs, const unsigned int p_outputs, const unsigned int p_params)</arglist>
    </member>
    <member kind="function">
      <type>unsigned int</type>
      <name>getNumInputs</name>
      <anchor>a1</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>unsigned int</type>
      <name>getNumOutputs</name>
      <anchor>a2</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual unsigned int</type>
      <name>getNumStates</name>
      <anchor>a3</anchor>
      <arglist>() const =0</arglist>
    </member>
    <member kind="function">
      <type>unsigned int</type>
      <name>getNumParams</name>
      <anchor>a4</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>InterfaceContainer *</type>
      <name>getInterfaceContainer</name>
      <anchor>a5</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>string</type>
      <name>getName</name>
      <anchor>a6</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>printInfo</name>
      <anchor>a7</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>invalidateU</name>
      <anchor>a8</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>invalidateY</name>
      <anchor>a9</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>invalidateX</name>
      <anchor>a10</anchor>
      <arglist>()=0</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>invalidateParam</name>
      <anchor>a11</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable">
      <type>SimInputVector</type>
      <name>u</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>SimOutputVector</type>
      <name>y</name>
      <anchor>o1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>SimParamVector</type>
      <name>param</name>
      <anchor>o2</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>InterfaceContainer</name>
    <filename>class_interface_container.html</filename>
    <member kind="function">
      <type></type>
      <name>InterfaceContainer</name>
      <anchor>a0</anchor>
      <arglist>(Sim *p_sim)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~InterfaceContainer</name>
      <anchor>a1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>Sim *</type>
      <name>getSim</name>
      <anchor>a2</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>ContinuousInterface *</type>
      <name>addContinuousInterface</name>
      <anchor>a3</anchor>
      <arglist>(const char *p_name, const unsigned int p_inputs, const unsigned int p_outputs, const unsigned int p_states, const unsigned int p_params)</arglist>
    </member>
    <member kind="function">
      <type>DiscreteInterface *</type>
      <name>addDiscreteInterface</name>
      <anchor>a4</anchor>
      <arglist>(const char *p_name, const unsigned int p_inputs, const unsigned int p_outputs, const unsigned int p_states, const unsigned int p_params, const double p_inputSampleTime, const double p_outputSampleTime, const double p_inputSampleOffset, const double p_outputSampleOffset)</arglist>
    </member>
    <member kind="function">
      <type>DiscreteInterface *</type>
      <name>addDiscreteInterface</name>
      <anchor>a5</anchor>
      <arglist>(const char *p_name, const unsigned int p_inputs, const unsigned int p_outputs, const unsigned int p_states, const unsigned int p_params, const double p_sampleTime)</arglist>
    </member>
    <member kind="function">
      <type>unsigned int</type>
      <name>getNumInputs</name>
      <anchor>a6</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>unsigned int</type>
      <name>getNumInputs</name>
      <anchor>a7</anchor>
      <arglist>(const unsigned int interfaceIndex)</arglist>
    </member>
    <member kind="function">
      <type>unsigned int</type>
      <name>getNumActiveInputPorts</name>
      <anchor>a8</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>unsigned int</type>
      <name>getActiveInputPortWidth</name>
      <anchor>a9</anchor>
      <arglist>(const unsigned int portIndex)</arglist>
    </member>
    <member kind="function">
      <type>unsigned int</type>
      <name>getNumOutputs</name>
      <anchor>a10</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>unsigned int</type>
      <name>getNumOutputs</name>
      <anchor>a11</anchor>
      <arglist>(const unsigned int interfaceIndex)</arglist>
    </member>
    <member kind="function">
      <type>unsigned int</type>
      <name>getNumActiveOutputPorts</name>
      <anchor>a12</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>unsigned int</type>
      <name>getActiveOutputPortWidth</name>
      <anchor>a13</anchor>
      <arglist>(const unsigned int portIndex)</arglist>
    </member>
    <member kind="function">
      <type>unsigned int</type>
      <name>getNumContinuousStates</name>
      <anchor>a14</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>unsigned int</type>
      <name>getNumContinuousStates</name>
      <anchor>a15</anchor>
      <arglist>(const unsigned int interfaceIndex)</arglist>
    </member>
    <member kind="function">
      <type>unsigned int</type>
      <name>getNumDiscreteStates</name>
      <anchor>a16</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>unsigned int</type>
      <name>getNumDiscreteStates</name>
      <anchor>a17</anchor>
      <arglist>(const unsigned int interfaceIndex)</arglist>
    </member>
    <member kind="function">
      <type>unsigned int</type>
      <name>getNumParams</name>
      <anchor>a18</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>unsigned int</type>
      <name>getNumParams</name>
      <anchor>a19</anchor>
      <arglist>(const unsigned int interfaceIndex)</arglist>
    </member>
    <member kind="function">
      <type>unsigned int</type>
      <name>getNumActiveParams</name>
      <anchor>a20</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>unsigned int</type>
      <name>getActiveParamWidth</name>
      <anchor>a21</anchor>
      <arglist>(const unsigned int portIndex)</arglist>
    </member>
    <member kind="function">
      <type>unsigned int</type>
      <name>getNumContinuousInterfaces</name>
      <anchor>a22</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>unsigned int</type>
      <name>getNumDiscreteInterfaces</name>
      <anchor>a23</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>unsigned int</type>
      <name>getNumInterfaces</name>
      <anchor>a24</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>getActiveInputPortSampleTime</name>
      <anchor>a25</anchor>
      <arglist>(const unsigned int portIndex)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>getActiveInputPortSampleOffset</name>
      <anchor>a26</anchor>
      <arglist>(const unsigned int portIndex)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>getActiveOutputPortSampleTime</name>
      <anchor>a27</anchor>
      <arglist>(const unsigned int portIndex)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>getActiveOutputPortSampleOffset</name>
      <anchor>a28</anchor>
      <arglist>(const unsigned int portIndex)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>printInfo</name>
      <anchor>a29</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>const real_T *</type>
      <name>getU</name>
      <anchor>a30</anchor>
      <arglist>(Interface *interface)</arglist>
    </member>
    <member kind="function">
      <type>real_T *</type>
      <name>getY</name>
      <anchor>a31</anchor>
      <arglist>(Interface *interface)</arglist>
    </member>
    <member kind="function">
      <type>real_T *</type>
      <name>getContinuousX</name>
      <anchor>a32</anchor>
      <arglist>(ContinuousInterface *interface)</arglist>
    </member>
    <member kind="function">
      <type>real_T *</type>
      <name>getDiscreteX</name>
      <anchor>a33</anchor>
      <arglist>(DiscreteInterface *interface)</arglist>
    </member>
    <member kind="function">
      <type>real_T *</type>
      <name>getDx</name>
      <anchor>a34</anchor>
      <arglist>(ContinuousInterface *interface)</arglist>
    </member>
    <member kind="function">
      <type>const real_T *</type>
      <name>getParam</name>
      <anchor>a35</anchor>
      <arglist>(Interface *interface)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>invalidateU</name>
      <anchor>a36</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>invalidateY</name>
      <anchor>a37</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>invalidateX</name>
      <anchor>a38</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>invalidateDx</name>
      <anchor>a39</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>invalidateParam</name>
      <anchor>a40</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>invalidateAll</name>
      <anchor>a41</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>const double</type>
      <name>SAMPLE_TIME_CONTINUOUS</name>
      <anchor>s0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>const double</type>
      <name>SAMPLE_OFFSET_CONTINUOUS</name>
      <anchor>s1</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Sim</name>
    <filename>class_sim.html</filename>
    <member kind="function">
      <type></type>
      <name>Sim</name>
      <anchor>a0</anchor>
      <arglist>(SimStruct *s)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~Sim</name>
      <anchor>a1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>start</name>
      <anchor>a2</anchor>
      <arglist>()=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>init_cond</name>
      <anchor>a3</anchor>
      <arglist>()=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>update</name>
      <anchor>a4</anchor>
      <arglist>()=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>derivative</name>
      <anchor>a5</anchor>
      <arglist>()=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>output</name>
      <anchor>a6</anchor>
      <arglist>()=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>terminate</name>
      <anchor>a7</anchor>
      <arglist>()=0</arglist>
    </member>
    <member kind="function">
      <type>SimStruct *</type>
      <name>getS</name>
      <anchor>a8</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>InterfaceContainer *</type>
      <name>getInterfaceContainer</name>
      <anchor>a9</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>ContinuousInterface *</type>
      <name>addContinuousInterface</name>
      <anchor>a10</anchor>
      <arglist>(const char *p_name, const unsigned int p_inputs, const unsigned int p_outputs, const unsigned int p_states, const unsigned int p_params)</arglist>
    </member>
    <member kind="function">
      <type>DiscreteInterface *</type>
      <name>addDiscreteInterface</name>
      <anchor>a11</anchor>
      <arglist>(const char *p_name, const unsigned int p_inputs, const unsigned int p_outputs, const unsigned int p_states, const unsigned int p_params, const double p_inputSampleTime, const double p_outputSampleTime, const double p_inputSampleOffset=0.0, const double p_outputSampleOffset=0.0)</arglist>
    </member>
    <member kind="function">
      <type>DiscreteInterface *</type>
      <name>addDiscreteInterface</name>
      <anchor>a12</anchor>
      <arglist>(const char *p_name, const unsigned int p_inputs, const unsigned int p_outputs, const unsigned int p_states, const unsigned int p_params, const double p_sampleTime)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>getSimTime</name>
      <anchor>a13</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>runOnce</name>
      <anchor>a14</anchor>
      <arglist>(const double time) const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>runOnce</name>
      <anchor>a15</anchor>
      <arglist>() const</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>SimContinuousStateVector</name>
    <filename>class_sim_continuous_state_vector.html</filename>
    <base>SimVector</base>
    <member kind="function">
      <type></type>
      <name>SimContinuousStateVector</name>
      <anchor>a0</anchor>
      <arglist>(ContinuousInterface *parentInterface, const unsigned int size)</arglist>
    </member>
    <member kind="function">
      <type>SimContinuousStateVector &amp;</type>
      <name>operator=</name>
      <anchor>a1</anchor>
      <arglist>(const MatrixAliasConstant &amp;copy)</arglist>
    </member>
    <member kind="function">
      <type>SimContinuousStateVector &amp;</type>
      <name>operator=</name>
      <anchor>a2</anchor>
      <arglist>(const SimContinuousStateVector &amp;copy)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const double *</type>
      <name>getSimIoPointer</name>
      <anchor>a3</anchor>
      <arglist>() const</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>SimDiscreteStateVector</name>
    <filename>class_sim_discrete_state_vector.html</filename>
    <base>SimVector</base>
    <member kind="function">
      <type></type>
      <name>SimDiscreteStateVector</name>
      <anchor>a0</anchor>
      <arglist>(DiscreteInterface *parentInterface, const unsigned int size)</arglist>
    </member>
    <member kind="function">
      <type>SimDiscreteStateVector &amp;</type>
      <name>operator=</name>
      <anchor>a1</anchor>
      <arglist>(const MatrixAliasConstant &amp;copy)</arglist>
    </member>
    <member kind="function">
      <type>SimDiscreteStateVector &amp;</type>
      <name>operator=</name>
      <anchor>a2</anchor>
      <arglist>(const SimDiscreteStateVector &amp;copy)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const double *</type>
      <name>getSimIoPointer</name>
      <anchor>a3</anchor>
      <arglist>() const</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>SimInputVector</name>
    <filename>class_sim_input_vector.html</filename>
    <base>SimVectorConstant</base>
    <member kind="function">
      <type></type>
      <name>SimInputVector</name>
      <anchor>a0</anchor>
      <arglist>(Interface *parentInterface, const unsigned int size)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const double *</type>
      <name>getSimIoPointer</name>
      <anchor>a1</anchor>
      <arglist>() const</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>SimInputVectorReadAccess</name>
    <filename>class_sim_input_vector_read_access.html</filename>
    <base>SimVectorReadAccess</base>
    <member kind="function">
      <type></type>
      <name>SimInputVectorReadAccess</name>
      <anchor>a0</anchor>
      <arglist>(SimVectorConstant *SVC)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const double &amp;</type>
      <name>readElement</name>
      <anchor>a1</anchor>
      <arglist>(const unsigned int row, const unsigned int column)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const double &amp;</type>
      <name>readElement</name>
      <anchor>a2</anchor>
      <arglist>(const unsigned int index)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>SimOutputVector</name>
    <filename>class_sim_output_vector.html</filename>
    <base>SimVector</base>
    <member kind="function">
      <type></type>
      <name>SimOutputVector</name>
      <anchor>a0</anchor>
      <arglist>(Interface *parentInterface, const unsigned int size)</arglist>
    </member>
    <member kind="function">
      <type>SimOutputVector &amp;</type>
      <name>operator=</name>
      <anchor>a1</anchor>
      <arglist>(const MatrixAliasConstant &amp;copy)</arglist>
    </member>
    <member kind="function">
      <type>SimOutputVector &amp;</type>
      <name>operator=</name>
      <anchor>a2</anchor>
      <arglist>(const SimOutputVector &amp;copy)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const double *</type>
      <name>getSimIoPointer</name>
      <anchor>a3</anchor>
      <arglist>() const</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>SimParamVector</name>
    <filename>class_sim_param_vector.html</filename>
    <base>SimVectorConstant</base>
    <member kind="function">
      <type></type>
      <name>SimParamVector</name>
      <anchor>a0</anchor>
      <arglist>(Interface *parentInterface, const unsigned int size)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const double *</type>
      <name>getSimIoPointer</name>
      <anchor>a1</anchor>
      <arglist>() const</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>SimStateDerivativeVector</name>
    <filename>class_sim_state_derivative_vector.html</filename>
    <base>SimVector</base>
    <member kind="function">
      <type></type>
      <name>SimStateDerivativeVector</name>
      <anchor>a0</anchor>
      <arglist>(ContinuousInterface *parentInterface, const unsigned int size)</arglist>
    </member>
    <member kind="function">
      <type>SimStateDerivativeVector &amp;</type>
      <name>operator=</name>
      <anchor>a1</anchor>
      <arglist>(const MatrixAliasConstant &amp;copy)</arglist>
    </member>
    <member kind="function">
      <type>SimStateDerivativeVector &amp;</type>
      <name>operator=</name>
      <anchor>a2</anchor>
      <arglist>(const SimStateDerivativeVector &amp;copy)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const double *</type>
      <name>getSimIoPointer</name>
      <anchor>a3</anchor>
      <arglist>() const</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>SimVector</name>
    <filename>class_sim_vector.html</filename>
    <base>SimVectorConstant</base>
    <base>ColumnVectorAlias</base>
    <member kind="function">
      <type></type>
      <name>SimVector</name>
      <anchor>a0</anchor>
      <arglist>(Interface *parentInterface, const unsigned int size)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~SimVector</name>
      <anchor>a1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>invalidate</name>
      <anchor>a2</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>_constructSimVector</name>
      <anchor>b0</anchor>
      <arglist>(Interface *parentInterface)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>SimVectorWriteAccess *</type>
      <name>m_simVectorWriteAccess</name>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>SimVectorConstant</name>
    <filename>class_sim_vector_constant.html</filename>
    <base virtualness="virtual">ColumnVectorAliasConstant</base>
    <member kind="function">
      <type></type>
      <name>SimVectorConstant</name>
      <anchor>a0</anchor>
      <arglist>(Interface *parentInterface, const unsigned int size)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~SimVectorConstant</name>
      <anchor>a1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>invalidate</name>
      <anchor>a2</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual const double *</type>
      <name>getSimIoPointer</name>
      <anchor>a3</anchor>
      <arglist>() const =0</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>_constructSimVectorConstant</name>
      <anchor>b0</anchor>
      <arglist>(Interface *parentInterface)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>InterfaceContainer *</type>
      <name>m_interfaceContainer</name>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>Interface *</type>
      <name>m_pInterface</name>
      <anchor>p1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>SimVectorReadAccess *</type>
      <name>m_simVectorReadAccess</name>
      <anchor>p2</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>SimVectorReadAccess</name>
    <filename>class_sim_vector_read_access.html</filename>
    <base>MatrixReadAccess</base>
    <member kind="function">
      <type></type>
      <name>SimVectorReadAccess</name>
      <anchor>a0</anchor>
      <arglist>(SimVectorConstant *SVC)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>invalidate</name>
      <anchor>a1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const double *</type>
      <name>getDataPointer</name>
      <anchor>a2</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>updateDataPointer</name>
      <anchor>a3</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>SimVectorConstant *</type>
      <name>m_simVectorConstant</name>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>bool</type>
      <name>m_dataPointerOk</name>
      <anchor>p1</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>SimVectorWriteAccess</name>
    <filename>class_sim_vector_write_access.html</filename>
    <base>MatrixWriteAccess</base>
    <member kind="function">
      <type></type>
      <name>SimVectorWriteAccess</name>
      <anchor>a0</anchor>
      <arglist>(SimVector *SV)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>invalidate</name>
      <anchor>a1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual double *</type>
      <name>getDataPointer</name>
      <anchor>a2</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>updateDataPointer</name>
      <anchor>a3</anchor>
      <arglist>()</arglist>
    </member>
  </compound>
</tagfile>
