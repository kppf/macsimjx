<?xml version='1.0' encoding='ISO-8859-1' standalone='yes'?>
<tagfile>
  <compound kind="page">
    <name>index</name>
    <title>MACSim Library: %Client Section</title>
    <filename>index</filename>
    <docanchor file="index">client_usage</docanchor>
    <docanchor file="index">client_doc</docanchor>
    <docanchor file="index">client_intro</docanchor>
  </compound>
  <compound kind="file">
    <name>client.h</name>
    <path>C:/Code/MACSim/client/include/</path>
    <filename>client_8h</filename>
    <includes id="interface_8h" name="interface.h" local="yes" imported="no">../../include/interface.h</includes>
  </compound>
  <compound kind="file">
    <name>doxygen_main.h</name>
    <path>C:/Code/MACSim/client/include/</path>
    <filename>doxygen__main_8h</filename>
  </compound>
  <compound kind="file">
    <name>macsim.h</name>
    <path>C:/Code/MACSim/client/include/</path>
    <filename>macsim_8h</filename>
    <includes id="client_8h" name="client.h" local="yes" imported="no">client.h</includes>
  </compound>
  <compound kind="file">
    <name>client.cpp</name>
    <path>C:/Code/MACSim/client/src/</path>
    <filename>client_8cpp</filename>
    <includes id="client_8h" name="client.h" local="yes" imported="no">../include/client.h</includes>
  </compound>
  <compound kind="file">
    <name>macsim.cpp</name>
    <path>C:/Code/MACSim/client/src/</path>
    <filename>macsim_8cpp</filename>
    <member kind="define">
      <type>#define</type>
      <name>SIM_CLASS_NAME</name>
      <anchor>a0</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>SIM_FILE_NAME</name>
      <anchor>a1</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>interface.h</name>
    <path>C:/Code/MACSim/include/</path>
    <filename>interface_8h</filename>
    <member kind="define">
      <type>#define</type>
      <name>MAC_CONFIG_PIPE_NAME</name>
      <anchor>a0</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>MAC_SIM_PIPE_NAME</name>
      <anchor>a1</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>MAC_CONFIG_CMD_INPUTS</name>
      <anchor>a2</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>MAC_CONFIG_CMD_OUTPUTS</name>
      <anchor>a3</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>MAC_CONFIG_CMD_SAMPLE</name>
      <anchor>a4</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>MAC_INVALID_RETURN</name>
      <anchor>a5</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Client</name>
    <filename>class_client.html</filename>
    <member kind="function">
      <type></type>
      <name>Client</name>
      <anchor>a0</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>Client</name>
      <anchor>a1</anchor>
      <arglist>(BOOL cacheData)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~Client</name>
      <anchor>a2</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>unsigned int</type>
      <name>requestNumInputs</name>
      <anchor>z3_0</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>unsigned int</type>
      <name>requestNumOutputs</name>
      <anchor>z3_1</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>unsigned int</type>
      <name>requestSampleInterval</name>
      <anchor>z3_2</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>requestSampleTime</name>
      <anchor>z3_3</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>unsigned int</type>
      <name>getNumInputs</name>
      <anchor>z4_0</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>unsigned int</type>
      <name>getNumOutputs</name>
      <anchor>z4_1</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>unsigned int</type>
      <name>getSampleInterval</name>
      <anchor>z4_2</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>getSampleTime</name>
      <anchor>z4_3</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>unsigned int</type>
      <name>getSimOutputs</name>
      <anchor>z5_0</anchor>
      <arglist>(IOPacket *in, IOPacket *out) const </arglist>
    </member>
    <member kind="function" protection="protected">
      <type>HANDLE</type>
      <name>openPipe</name>
      <anchor>b0</anchor>
      <arglist>(const char *pipeName) const </arglist>
    </member>
    <member kind="function" protection="protected">
      <type>unsigned int</type>
      <name>configDataRequest</name>
      <anchor>b1</anchor>
      <arglist>(HANDLE hPipe, DWORD msgId) const </arglist>
    </member>
    <member kind="function" protection="protected">
      <type>unsigned int</type>
      <name>configDataRequest</name>
      <anchor>b2</anchor>
      <arglist>(const char *pipeName, DWORD msgId) const </arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>initialise</name>
      <anchor>b3</anchor>
      <arglist>(BOOL cacheData)</arglist>
    </member>
    <member kind="variable" protection="private">
      <type>BOOL</type>
      <name>m_dataCached</name>
      <anchor>r0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>HANDLE</type>
      <name>m_simPipe</name>
      <anchor>z2_0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>unsigned int</type>
      <name>m_inputs</name>
      <anchor>z2_1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>unsigned int</type>
      <name>m_outputs</name>
      <anchor>z2_2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>unsigned int</type>
      <name>m_sampleInterval</name>
      <anchor>z2_3</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>ClientException</name>
    <filename>class_client_exception.html</filename>
    <member kind="function">
      <type></type>
      <name>ClientException</name>
      <anchor>a0</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>ClientException</name>
      <anchor>a1</anchor>
      <arglist>(const char *p_desc)</arglist>
    </member>
    <member kind="function">
      <type>const char *</type>
      <name>getDescription</name>
      <anchor>a2</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>const char *</type>
      <name>m_desc</name>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>IOPacket</name>
    <filename>class_i_o_packet.html</filename>
    <member kind="function">
      <type></type>
      <name>IOPacket</name>
      <anchor>a0</anchor>
      <arglist>(const unsigned int p_nValues)</arglist>
    </member>
    <member kind="variable">
      <type>unsigned int</type>
      <name>m_nValues</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>double *</type>
      <name>m_values</name>
      <anchor>o1</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>IOPacketWrapper</name>
    <filename>class_i_o_packet_wrapper.html</filename>
    <base>IOPacket</base>
    <member kind="function">
      <type></type>
      <name>IOPacketWrapper</name>
      <anchor>a0</anchor>
      <arglist>(const unsigned int p_nValues)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~IOPacketWrapper</name>
      <anchor>a1</anchor>
      <arglist>()</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>MACSimClient</name>
    <filename>class_m_a_c_sim_client.html</filename>
    <member kind="function">
      <type></type>
      <name>MACSimClient</name>
      <anchor>a0</anchor>
      <arglist>(SimStruct *s)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~MACSimClient</name>
      <anchor>a1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>output</name>
      <anchor>z7_0</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>start</name>
      <anchor>z7_1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>init_cond</name>
      <anchor>z7_2</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>update</name>
      <anchor>z7_3</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>derivative</name>
      <anchor>z7_4</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>terminate</name>
      <anchor>z7_5</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable" protection="private">
      <type>DiscreteInterface *</type>
      <name>m_interface</name>
      <anchor>r0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Client *</type>
      <name>m_client</name>
      <anchor>r1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>IOPacketWrapper *</type>
      <name>m_inPacket</name>
      <anchor>z6_0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>IOPacket *</type>
      <name>m_outPacket</name>
      <anchor>z6_1</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="dir">
    <name>MACSim/client/</name>
    <path>C:/Code/MACSim/client/</path>
    <filename>dir_000001.html</filename>
    <dir>MACSim/client/include/</dir>
    <dir>MACSim/client/src/</dir>
  </compound>
  <compound kind="dir">
    <name>MACSim/include/</name>
    <path>C:/Code/MACSim/include/</path>
    <filename>dir_000004.html</filename>
    <file>interface.h</file>
  </compound>
  <compound kind="dir">
    <name>MACSim/client/include/</name>
    <path>C:/Code/MACSim/client/include/</path>
    <filename>dir_000002.html</filename>
    <file>client.h</file>
    <file>doxygen_main.h</file>
    <file>macsim.h</file>
  </compound>
  <compound kind="dir">
    <name>MACSim/</name>
    <path>C:/Code/MACSim/</path>
    <filename>dir_000000.html</filename>
    <dir>MACSim/client/</dir>
    <dir>MACSim/include/</dir>
  </compound>
  <compound kind="dir">
    <name>MACSim/client/src/</name>
    <path>C:/Code/MACSim/client/src/</path>
    <filename>dir_000003.html</filename>
    <file>client.cpp</file>
    <file>macsim.cpp</file>
  </compound>
</tagfile>
