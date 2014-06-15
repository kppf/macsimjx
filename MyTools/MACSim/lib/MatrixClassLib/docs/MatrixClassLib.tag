<?xml version='1.0' encoding='ISO-8859-1' standalone='yes' ?>
<tagfile>
  <compound kind="page">
    <name>index</name>
    <title>The MatrixClass Library</title>
    <filename>index</filename>
    <docanchor file="index">usage_morestandardoperators</docanchor>
    <docanchor file="index">implementation_constantalias</docanchor>
    <docanchor file="index">implementation_standalone</docanchor>
    <docanchor file="index">intro</docanchor>
    <docanchor file="index">implementation_alias</docanchor>
    <docanchor file="index">implementation</docanchor>
    <docanchor file="index">usage</docanchor>
    <docanchor file="index">usage_standardoperators</docanchor>
  </compound>
  <compound kind="file">
    <name>matrix.h</name>
    <path>C:/Code/lib/MatrixClassLib/code/include/</path>
    <filename>matrix_8h</filename>
    <includes id="matrix__container_8h" name="matrix_container.h" local="yes" imported="no">matrix_container.h</includes>
    <includes id="matrix__operator_8h" name="matrix_operator.h" local="yes" imported="no">matrix_operator.h</includes>
    <includes id="matrix__access_8h" name="matrix_access.h" local="yes" imported="no">matrix_access.h</includes>
  </compound>
  <compound kind="file">
    <name>matrix_access.h</name>
    <path>C:/Code/lib/MatrixClassLib/code/include/</path>
    <filename>matrix__access_8h</filename>
  </compound>
  <compound kind="file">
    <name>matrix_container.h</name>
    <path>C:/Code/lib/MatrixClassLib/code/include/</path>
    <filename>matrix__container_8h</filename>
  </compound>
  <compound kind="file">
    <name>matrix_operator.h</name>
    <path>C:/Code/lib/MatrixClassLib/code/include/</path>
    <filename>matrix__operator_8h</filename>
    <includes id="matrix__access_8h" name="matrix_access.h" local="yes" imported="no">matrix_access.h</includes>
  </compound>
  <compound kind="file">
    <name>matrix.cpp</name>
    <path>C:/Code/lib/MatrixClassLib/code/src/</path>
    <filename>matrix_8cpp</filename>
    <includes id="matrix_8h" name="matrix.h" local="yes" imported="no">../include/matrix.h</includes>
    <includes id="matrix__container_8h" name="matrix_container.h" local="yes" imported="no">../include/matrix_container.h</includes>
    <includes id="matrix__access_8h" name="matrix_access.h" local="yes" imported="no">../include/matrix_access.h</includes>
    <includes id="matrix__operator_8h" name="matrix_operator.h" local="yes" imported="no">../include/matrix_operator.h</includes>
  </compound>
  <compound kind="file">
    <name>matrix_access.cpp</name>
    <path>C:/Code/lib/MatrixClassLib/code/src/</path>
    <filename>matrix__access_8cpp</filename>
    <includes id="matrix__access_8h" name="matrix_access.h" local="yes" imported="no">../include/matrix_access.h</includes>
    <includes id="matrix__container_8h" name="matrix_container.h" local="yes" imported="no">../include/matrix_container.h</includes>
    <includes id="matrix_8h" name="matrix.h" local="yes" imported="no">../include/matrix.h</includes>
  </compound>
  <compound kind="file">
    <name>matrix_operator.cpp</name>
    <path>C:/Code/lib/MatrixClassLib/code/src/</path>
    <filename>matrix__operator_8cpp</filename>
    <includes id="matrix__operator_8h" name="matrix_operator.h" local="yes" imported="no">../include/matrix_operator.h</includes>
    <includes id="matrix_8h" name="matrix.h" local="yes" imported="no">../include/matrix.h</includes>
    <member kind="function">
      <type>double</type>
      <name>_rand</name>
      <anchorfile>matrix__operator_8cpp.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>()</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>ColumnVector</name>
    <filename>class_column_vector.html</filename>
    <base>Matrix</base>
    <base>ColumnVectorAlias</base>
    <member kind="function">
      <type></type>
      <name>ColumnVector</name>
      <anchorfile>class_column_vector.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>ColumnVector</name>
      <anchorfile>class_column_vector.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>(const unsigned int size)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>ColumnVector</name>
      <anchorfile>class_column_vector.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>(const MatrixAliasConstant &amp;copy)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>ColumnVector</name>
      <anchorfile>class_column_vector.html</anchorfile>
      <anchor>a3</anchor>
      <arglist>(ColumnVector &amp;copy)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~ColumnVector</name>
      <anchorfile>class_column_vector.html</anchorfile>
      <anchor>a4</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>ColumnVector &amp;</type>
      <name>operator=</name>
      <anchorfile>class_column_vector.html</anchorfile>
      <anchor>a5</anchor>
      <arglist>(const MatrixAliasConstant &amp;copy)</arglist>
    </member>
    <member kind="function">
      <type>ColumnVector &amp;</type>
      <name>operator=</name>
      <anchorfile>class_column_vector.html</anchorfile>
      <anchor>a6</anchor>
      <arglist>(const ColumnVector &amp;copy)</arglist>
    </member>
    <member kind="variable">
      <type>CVWO_EqualsElementCopyResize</type>
      <name>equals</name>
      <anchorfile>class_column_vector.html</anchorfile>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>CVWO_Resize</type>
      <name>resize</name>
      <anchorfile>class_column_vector.html</anchorfile>
      <anchor>o1</anchor>
      <arglist></arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>_constructColumnVector</name>
      <anchorfile>class_column_vector.html</anchorfile>
      <anchor>b0</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>_constructColumnVector</name>
      <anchorfile>class_column_vector.html</anchorfile>
      <anchor>b1</anchor>
      <arglist>(const MatrixAliasConstant &amp;copy)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>ColumnVectorAlias</name>
    <filename>class_column_vector_alias.html</filename>
    <base virtualness="virtual">ColumnVectorAliasConstant</base>
    <base virtualness="virtual">MatrixAlias</base>
    <member kind="function">
      <type></type>
      <name>ColumnVectorAlias</name>
      <anchorfile>class_column_vector_alias.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(const double *data, const unsigned int size)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>ColumnVectorAlias</name>
      <anchorfile>class_column_vector_alias.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>(const MatrixAliasConstant *alias)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>ColumnVectorAlias</name>
      <anchorfile>class_column_vector_alias.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>(const MatrixAliasConstant &amp;copy)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>ColumnVectorAlias</name>
      <anchorfile>class_column_vector_alias.html</anchorfile>
      <anchor>a3</anchor>
      <arglist>(const ColumnVectorAlias &amp;copy)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~ColumnVectorAlias</name>
      <anchorfile>class_column_vector_alias.html</anchorfile>
      <anchor>a4</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>ColumnVectorAlias &amp;</type>
      <name>operator=</name>
      <anchorfile>class_column_vector_alias.html</anchorfile>
      <anchor>a5</anchor>
      <arglist>(const MatrixAliasConstant &amp;copy)</arglist>
    </member>
    <member kind="function">
      <type>ColumnVectorAlias &amp;</type>
      <name>operator=</name>
      <anchorfile>class_column_vector_alias.html</anchorfile>
      <anchor>a6</anchor>
      <arglist>(const ColumnVectorAlias &amp;copy)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>_constructColumnVectorAlias</name>
      <anchorfile>class_column_vector_alias.html</anchorfile>
      <anchor>b0</anchor>
      <arglist>()</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>ColumnVectorAliasConstant</name>
    <filename>class_column_vector_alias_constant.html</filename>
    <base virtualness="virtual">MatrixAliasConstant</base>
    <member kind="function">
      <type></type>
      <name>ColumnVectorAliasConstant</name>
      <anchorfile>class_column_vector_alias_constant.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(const double *data, const unsigned int size)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>ColumnVectorAliasConstant</name>
      <anchorfile>class_column_vector_alias_constant.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>(const MatrixAliasConstant *alias)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>ColumnVectorAliasConstant</name>
      <anchorfile>class_column_vector_alias_constant.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>(const MatrixAliasConstant &amp;copy)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>ColumnVectorAliasConstant</name>
      <anchorfile>class_column_vector_alias_constant.html</anchorfile>
      <anchor>a3</anchor>
      <arglist>(const ColumnVectorAliasConstant &amp;copy)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~ColumnVectorAliasConstant</name>
      <anchorfile>class_column_vector_alias_constant.html</anchorfile>
      <anchor>a4</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>ColumnVectorAliasConstant &amp;</type>
      <name>operator=</name>
      <anchorfile>class_column_vector_alias_constant.html</anchorfile>
      <anchor>a5</anchor>
      <arglist>(const MatrixAliasConstant &amp;copy)</arglist>
    </member>
    <member kind="function">
      <type>ColumnVectorAliasConstant &amp;</type>
      <name>operator=</name>
      <anchorfile>class_column_vector_alias_constant.html</anchorfile>
      <anchor>a6</anchor>
      <arglist>(const ColumnVectorAliasConstant &amp;copy)</arglist>
    </member>
    <member kind="variable">
      <type>CVRO_CrossProduct</type>
      <name>cross</name>
      <anchorfile>class_column_vector_alias_constant.html</anchorfile>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>CVRO_DotProduct</type>
      <name>dot</name>
      <anchorfile>class_column_vector_alias_constant.html</anchorfile>
      <anchor>o1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>CVRO_Direction</type>
      <name>direction</name>
      <anchorfile>class_column_vector_alias_constant.html</anchorfile>
      <anchor>o2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>CVRO_GetSize</type>
      <name>getSize</name>
      <anchorfile>class_column_vector_alias_constant.html</anchorfile>
      <anchor>o3</anchor>
      <arglist></arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>_constructColumnVectorAliasConstant</name>
      <anchorfile>class_column_vector_alias_constant.html</anchorfile>
      <anchor>b0</anchor>
      <arglist>()</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>ColumnVectorReadOperator</name>
    <filename>class_column_vector_read_operator.html</filename>
    <base>MatrixReadOperator</base>
    <member kind="function">
      <type></type>
      <name>ColumnVectorReadOperator</name>
      <anchorfile>class_column_vector_read_operator.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>ColumnVectorReadOperator</name>
      <anchorfile>class_column_vector_read_operator.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>(ColumnVectorAliasConstant *columnVectorAliasConstant)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>_constructColumnVectorReadOperator</name>
      <anchorfile>class_column_vector_read_operator.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>(ColumnVectorAliasConstant *columnVectorAliasConstant)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>ColumnVectorAliasConstant *</type>
      <name>m_thisMatrix</name>
      <anchorfile>class_column_vector_read_operator.html</anchorfile>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>ColumnVectorWriteOperator</name>
    <filename>class_column_vector_write_operator.html</filename>
    <base>MatrixWriteOperator</base>
    <member kind="function">
      <type></type>
      <name>ColumnVectorWriteOperator</name>
      <anchorfile>class_column_vector_write_operator.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>ColumnVectorWriteOperator</name>
      <anchorfile>class_column_vector_write_operator.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>(ColumnVectorAlias *columnVectorAlias)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>_constructColumnVectorWriteOperator</name>
      <anchorfile>class_column_vector_write_operator.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>(ColumnVectorAlias *columnVectorAlias)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>ColumnVectorAlias *</type>
      <name>m_thisMatrix</name>
      <anchorfile>class_column_vector_write_operator.html</anchorfile>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>CVRO_CrossProduct</name>
    <filename>class_c_v_r_o___cross_product.html</filename>
    <base>ColumnVectorReadOperator</base>
    <member kind="function">
      <type>ColumnVector</type>
      <name>operator()</name>
      <anchorfile>class_c_v_r_o___cross_product.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(const ColumnVectorAliasConstant &amp;operand) const </arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>CVRO_Direction</name>
    <filename>class_c_v_r_o___direction.html</filename>
    <base>ColumnVectorReadOperator</base>
    <member kind="function">
      <type>ColumnVector</type>
      <name>operator()</name>
      <anchorfile>class_c_v_r_o___direction.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>() const </arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>CVRO_DotProduct</name>
    <filename>class_c_v_r_o___dot_product.html</filename>
    <base>ColumnVectorReadOperator</base>
    <member kind="function">
      <type>double</type>
      <name>operator()</name>
      <anchorfile>class_c_v_r_o___dot_product.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(const ColumnVectorAliasConstant &amp;operand) const </arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>CVRO_GetSize</name>
    <filename>class_c_v_r_o___get_size.html</filename>
    <base>ColumnVectorReadOperator</base>
    <member kind="function">
      <type>const unsigned int</type>
      <name>operator()</name>
      <anchorfile>class_c_v_r_o___get_size.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>() const </arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>CVWO_EqualsElementCopyResize</name>
    <filename>class_c_v_w_o___equals_element_copy_resize.html</filename>
    <base>ColumnVectorWriteOperator</base>
    <member kind="function">
      <type>void</type>
      <name>operator()</name>
      <anchorfile>class_c_v_w_o___equals_element_copy_resize.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(const MatrixAliasConstant &amp;copy) const </arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>CVWO_Resize</name>
    <filename>class_c_v_w_o___resize.html</filename>
    <base>ColumnVectorWriteOperator</base>
    <member kind="function">
      <type>void</type>
      <name>operator()</name>
      <anchorfile>class_c_v_w_o___resize.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(const unsigned int size) const </arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Matrix</name>
    <filename>class_matrix.html</filename>
    <base virtualness="virtual">MatrixAlias</base>
    <member kind="function">
      <type></type>
      <name>Matrix</name>
      <anchorfile>class_matrix.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>Matrix</name>
      <anchorfile>class_matrix.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>(const unsigned int rows, const unsigned int columns)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>Matrix</name>
      <anchorfile>class_matrix.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>(const MatrixAliasConstant &amp;copy)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>Matrix</name>
      <anchorfile>class_matrix.html</anchorfile>
      <anchor>a3</anchor>
      <arglist>(const Matrix &amp;copy)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~Matrix</name>
      <anchorfile>class_matrix.html</anchorfile>
      <anchor>a4</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>Matrix &amp;</type>
      <name>operator=</name>
      <anchorfile>class_matrix.html</anchorfile>
      <anchor>a5</anchor>
      <arglist>(const MatrixAliasConstant &amp;copy)</arglist>
    </member>
    <member kind="function">
      <type>Matrix &amp;</type>
      <name>operator=</name>
      <anchorfile>class_matrix.html</anchorfile>
      <anchor>a6</anchor>
      <arglist>(const Matrix &amp;copy)</arglist>
    </member>
    <member kind="variable">
      <type>MWO_EqualsElementCopyResize</type>
      <name>equals</name>
      <anchorfile>class_matrix.html</anchorfile>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>MWO_Resize</type>
      <name>resize</name>
      <anchorfile>class_matrix.html</anchorfile>
      <anchor>o1</anchor>
      <arglist></arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>_constructMatrix</name>
      <anchorfile>class_matrix.html</anchorfile>
      <anchor>b0</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>_constructMatrix</name>
      <anchorfile>class_matrix.html</anchorfile>
      <anchor>b1</anchor>
      <arglist>(const MatrixAliasConstant &amp;copy)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>MatrixAlias</name>
    <filename>class_matrix_alias.html</filename>
    <base virtualness="virtual">MatrixAliasConstant</base>
    <member kind="function">
      <type></type>
      <name>MatrixAlias</name>
      <anchorfile>class_matrix_alias.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(const double *data, const unsigned int rows, const unsigned int columns)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>MatrixAlias</name>
      <anchorfile>class_matrix_alias.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>(const MatrixAliasConstant *alias)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>MatrixAlias</name>
      <anchorfile>class_matrix_alias.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>(const MatrixAliasConstant &amp;copy)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>MatrixAlias</name>
      <anchorfile>class_matrix_alias.html</anchorfile>
      <anchor>a3</anchor>
      <arglist>(const MatrixAlias &amp;copy)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>MatrixAlias</name>
      <anchorfile>class_matrix_alias.html</anchorfile>
      <anchor>a4</anchor>
      <arglist>(MatrixContainer *container, MatrixReadAccess *r_access, MatrixWriteAccess *w_access)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~MatrixAlias</name>
      <anchorfile>class_matrix_alias.html</anchorfile>
      <anchor>a5</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>MatrixAlias &amp;</type>
      <name>operator=</name>
      <anchorfile>class_matrix_alias.html</anchorfile>
      <anchor>a6</anchor>
      <arglist>(const MatrixAliasConstant &amp;copy)</arglist>
    </member>
    <member kind="function">
      <type>MatrixAlias &amp;</type>
      <name>operator=</name>
      <anchorfile>class_matrix_alias.html</anchorfile>
      <anchor>a7</anchor>
      <arglist>(const MatrixAlias &amp;copy)</arglist>
    </member>
    <member kind="function">
      <type>double &amp;</type>
      <name>operator()</name>
      <anchorfile>class_matrix_alias.html</anchorfile>
      <anchor>a8</anchor>
      <arglist>(const unsigned int row, const unsigned int column) const </arglist>
    </member>
    <member kind="function">
      <type>double &amp;</type>
      <name>operator()</name>
      <anchorfile>class_matrix_alias.html</anchorfile>
      <anchor>a9</anchor>
      <arglist>(const unsigned int index) const </arglist>
    </member>
    <member kind="function">
      <type>MatrixAlias &amp;</type>
      <name>operator+=</name>
      <anchorfile>class_matrix_alias.html</anchorfile>
      <anchor>a10</anchor>
      <arglist>(const MatrixAliasConstant &amp;operand)</arglist>
    </member>
    <member kind="function">
      <type>MatrixAlias &amp;</type>
      <name>operator-=</name>
      <anchorfile>class_matrix_alias.html</anchorfile>
      <anchor>a11</anchor>
      <arglist>(const MatrixAliasConstant &amp;operand)</arglist>
    </member>
    <member kind="function">
      <type>MatrixAlias &amp;</type>
      <name>operator *=</name>
      <anchorfile>class_matrix_alias.html</anchorfile>
      <anchor>a12</anchor>
      <arglist>(const MatrixAliasConstant &amp;operand)</arglist>
    </member>
    <member kind="function">
      <type>MatrixAlias &amp;</type>
      <name>operator *=</name>
      <anchorfile>class_matrix_alias.html</anchorfile>
      <anchor>a13</anchor>
      <arglist>(const double &amp;operand)</arglist>
    </member>
    <member kind="function">
      <type>MatrixAlias &amp;</type>
      <name>operator/=</name>
      <anchorfile>class_matrix_alias.html</anchorfile>
      <anchor>a14</anchor>
      <arglist>(const double &amp;operand)</arglist>
    </member>
    <member kind="variable">
      <type>MatrixWriteAccess *</type>
      <name>m_matrixWriteAccess</name>
      <anchorfile>class_matrix_alias.html</anchorfile>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>MWO_Element</type>
      <name>element</name>
      <anchorfile>class_matrix_alias.html</anchorfile>
      <anchor>o1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>MWO_EqualsElementCopy</type>
      <name>equals</name>
      <anchorfile>class_matrix_alias.html</anchorfile>
      <anchor>o2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>MWO_Zero</type>
      <name>zero</name>
      <anchorfile>class_matrix_alias.html</anchorfile>
      <anchor>o3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>MWO_Set</type>
      <name>set</name>
      <anchorfile>class_matrix_alias.html</anchorfile>
      <anchor>o4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>MWO_Normalise</type>
      <name>normalise</name>
      <anchorfile>class_matrix_alias.html</anchorfile>
      <anchor>o5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>MWO_Randomise</type>
      <name>rand</name>
      <anchorfile>class_matrix_alias.html</anchorfile>
      <anchor>o6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>MWO_SubMatrixAlias</type>
      <name>subMatrix</name>
      <anchorfile>class_matrix_alias.html</anchorfile>
      <anchor>o7</anchor>
      <arglist></arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>_constructMatrixAlias</name>
      <anchorfile>class_matrix_alias.html</anchorfile>
      <anchor>b0</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>_constructMatrixAlias</name>
      <anchorfile>class_matrix_alias.html</anchorfile>
      <anchor>b1</anchor>
      <arglist>(MatrixWriteAccess *w_access)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>MatrixAliasConstant</name>
    <filename>class_matrix_alias_constant.html</filename>
    <member kind="function">
      <type></type>
      <name>MatrixAliasConstant</name>
      <anchorfile>class_matrix_alias_constant.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(const double *data, const unsigned int rows, const unsigned int columns)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>MatrixAliasConstant</name>
      <anchorfile>class_matrix_alias_constant.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>(const MatrixAliasConstant *alias)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>MatrixAliasConstant</name>
      <anchorfile>class_matrix_alias_constant.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>(const MatrixAliasConstant &amp;copy)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>MatrixAliasConstant</name>
      <anchorfile>class_matrix_alias_constant.html</anchorfile>
      <anchor>a3</anchor>
      <arglist>(MatrixContainer *container, MatrixReadAccess *access)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>MatrixAliasConstant</name>
      <anchorfile>class_matrix_alias_constant.html</anchorfile>
      <anchor>a4</anchor>
      <arglist>(MatrixReadAccess *access, const double *data, const unsigned int rows, const unsigned int columns)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~MatrixAliasConstant</name>
      <anchorfile>class_matrix_alias_constant.html</anchorfile>
      <anchor>a5</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>const double &amp;</type>
      <name>operator()</name>
      <anchorfile>class_matrix_alias_constant.html</anchorfile>
      <anchor>a6</anchor>
      <arglist>(const unsigned int row, const unsigned int column) const </arglist>
    </member>
    <member kind="function">
      <type>const double &amp;</type>
      <name>operator()</name>
      <anchorfile>class_matrix_alias_constant.html</anchorfile>
      <anchor>a7</anchor>
      <arglist>(const unsigned int index) const </arglist>
    </member>
    <member kind="function">
      <type>Matrix</type>
      <name>operator+</name>
      <anchorfile>class_matrix_alias_constant.html</anchorfile>
      <anchor>a8</anchor>
      <arglist>(const MatrixAliasConstant &amp;operand) const </arglist>
    </member>
    <member kind="function">
      <type>Matrix</type>
      <name>operator-</name>
      <anchorfile>class_matrix_alias_constant.html</anchorfile>
      <anchor>a9</anchor>
      <arglist>(const MatrixAliasConstant &amp;operand) const </arglist>
    </member>
    <member kind="function">
      <type>Matrix</type>
      <name>operator-</name>
      <anchorfile>class_matrix_alias_constant.html</anchorfile>
      <anchor>a10</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>Matrix</type>
      <name>operator *</name>
      <anchorfile>class_matrix_alias_constant.html</anchorfile>
      <anchor>a11</anchor>
      <arglist>(const MatrixAliasConstant &amp;operand) const </arglist>
    </member>
    <member kind="function">
      <type>Matrix</type>
      <name>operator *</name>
      <anchorfile>class_matrix_alias_constant.html</anchorfile>
      <anchor>a12</anchor>
      <arglist>(const double &amp;operand) const </arglist>
    </member>
    <member kind="function">
      <type>Matrix</type>
      <name>operator/</name>
      <anchorfile>class_matrix_alias_constant.html</anchorfile>
      <anchor>a13</anchor>
      <arglist>(const double &amp;operand) const </arglist>
    </member>
    <member kind="function">
      <type>MatrixAliasConstant &amp;</type>
      <name>operator=</name>
      <anchorfile>class_matrix_alias_constant.html</anchorfile>
      <anchor>a14</anchor>
      <arglist>(const MatrixAliasConstant &amp;copy)</arglist>
    </member>
    <member kind="function">
      <type>const unsigned int</type>
      <name>getRows</name>
      <anchorfile>class_matrix_alias_constant.html</anchorfile>
      <anchor>a15</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>const unsigned int</type>
      <name>getColumns</name>
      <anchorfile>class_matrix_alias_constant.html</anchorfile>
      <anchor>a16</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>const double *</type>
      <name>getDataPointer</name>
      <anchorfile>class_matrix_alias_constant.html</anchorfile>
      <anchor>a17</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="variable">
      <type>MatrixContainer *</type>
      <name>m_matrixContainer</name>
      <anchorfile>class_matrix_alias_constant.html</anchorfile>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>MatrixReadAccess *</type>
      <name>m_matrixReadAccess</name>
      <anchorfile>class_matrix_alias_constant.html</anchorfile>
      <anchor>o1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>MRO_Element</type>
      <name>element</name>
      <anchorfile>class_matrix_alias_constant.html</anchorfile>
      <anchor>o2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>MRO_Add</type>
      <name>add</name>
      <anchorfile>class_matrix_alias_constant.html</anchorfile>
      <anchor>o3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>MRO_Subtract</type>
      <name>subtract</name>
      <anchorfile>class_matrix_alias_constant.html</anchorfile>
      <anchor>o4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>MRO_Negative</type>
      <name>negative</name>
      <anchorfile>class_matrix_alias_constant.html</anchorfile>
      <anchor>o5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>MRO_Multiply</type>
      <name>multiply</name>
      <anchorfile>class_matrix_alias_constant.html</anchorfile>
      <anchor>o6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>MRO_Divide</type>
      <name>divide</name>
      <anchorfile>class_matrix_alias_constant.html</anchorfile>
      <anchor>o7</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>MRO_Print</type>
      <name>print</name>
      <anchorfile>class_matrix_alias_constant.html</anchorfile>
      <anchor>o8</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>MRO_PrintMatlabFriendly</type>
      <name>printM</name>
      <anchorfile>class_matrix_alias_constant.html</anchorfile>
      <anchor>o9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>MRO_SubMatrixAliasConstant</type>
      <name>subMatrix</name>
      <anchorfile>class_matrix_alias_constant.html</anchorfile>
      <anchor>o10</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>MRO_SizeEqual</type>
      <name>sizeEqual</name>
      <anchorfile>class_matrix_alias_constant.html</anchorfile>
      <anchor>o11</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>MRO_IsSquareMatrix</type>
      <name>isSquareMatrix</name>
      <anchorfile>class_matrix_alias_constant.html</anchorfile>
      <anchor>o12</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>MRO_IsRowVector</type>
      <name>isRowVector</name>
      <anchorfile>class_matrix_alias_constant.html</anchorfile>
      <anchor>o13</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>MRO_IsColumnVector</type>
      <name>isColumnVector</name>
      <anchorfile>class_matrix_alias_constant.html</anchorfile>
      <anchor>o14</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>MRO_Transpose</type>
      <name>transpose</name>
      <anchorfile>class_matrix_alias_constant.html</anchorfile>
      <anchor>o15</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>MRO_Absolute</type>
      <name>absolute</name>
      <anchorfile>class_matrix_alias_constant.html</anchorfile>
      <anchor>o16</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>MRO_RowSum</type>
      <name>rowSum</name>
      <anchorfile>class_matrix_alias_constant.html</anchorfile>
      <anchor>o17</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>MRO_ColumnSum</type>
      <name>columnSum</name>
      <anchorfile>class_matrix_alias_constant.html</anchorfile>
      <anchor>o18</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>MRO_Maximum</type>
      <name>maximum</name>
      <anchorfile>class_matrix_alias_constant.html</anchorfile>
      <anchor>o19</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>MRO_Minimum</type>
      <name>minimum</name>
      <anchorfile>class_matrix_alias_constant.html</anchorfile>
      <anchor>o20</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>MRO_InfinityNorm</type>
      <name>infinityNorm</name>
      <anchorfile>class_matrix_alias_constant.html</anchorfile>
      <anchor>o21</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>MRO_FrobeniusNorm</type>
      <name>frobeniusNorm</name>
      <anchorfile>class_matrix_alias_constant.html</anchorfile>
      <anchor>o22</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>MRO_SquaredElements</type>
      <name>squaredElements</name>
      <anchorfile>class_matrix_alias_constant.html</anchorfile>
      <anchor>o23</anchor>
      <arglist></arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>_constructMatrixAliasConstant</name>
      <anchorfile>class_matrix_alias_constant.html</anchorfile>
      <anchor>b0</anchor>
      <arglist>(const double *data, const unsigned int rows, const unsigned int columns)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>_constructMatrixAliasConstant</name>
      <anchorfile>class_matrix_alias_constant.html</anchorfile>
      <anchor>b1</anchor>
      <arglist>(MatrixContainer *container, MatrixReadAccess *access)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>_constructMatrixAliasConstant</name>
      <anchorfile>class_matrix_alias_constant.html</anchorfile>
      <anchor>b2</anchor>
      <arglist>(MatrixContainer *container)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>_constructMatrixAliasConstant</name>
      <anchorfile>class_matrix_alias_constant.html</anchorfile>
      <anchor>b3</anchor>
      <arglist>(MatrixReadAccess *access, const double *data, const unsigned int rows, const unsigned int columns)</arglist>
    </member>
    <member kind="friend">
      <type>friend Matrix</type>
      <name>operator *</name>
      <anchorfile>class_matrix_alias_constant.html</anchorfile>
      <anchor>n0</anchor>
      <arglist>(const double &amp;operand1, const MatrixAliasConstant &amp;operand2)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>MatrixContainer</name>
    <filename>class_matrix_container.html</filename>
    <member kind="function">
      <type></type>
      <name>MatrixContainer</name>
      <anchorfile>class_matrix_container.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(const double *data, const unsigned int rows, const unsigned int columns)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>MatrixContainer</name>
      <anchorfile>class_matrix_container.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>(const MatrixContainer &amp;copy)</arglist>
    </member>
    <member kind="function">
      <type>unsigned int</type>
      <name>getRows</name>
      <anchorfile>class_matrix_container.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>unsigned int</type>
      <name>getColumns</name>
      <anchorfile>class_matrix_container.html</anchorfile>
      <anchor>a3</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual double *</type>
      <name>getDataPointer</name>
      <anchorfile>class_matrix_container.html</anchorfile>
      <anchor>a4</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setRows</name>
      <anchorfile>class_matrix_container.html</anchorfile>
      <anchor>a5</anchor>
      <arglist>(unsigned int num)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setColumns</name>
      <anchorfile>class_matrix_container.html</anchorfile>
      <anchor>a6</anchor>
      <arglist>(unsigned int num)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setDataPointer</name>
      <anchorfile>class_matrix_container.html</anchorfile>
      <anchor>a7</anchor>
      <arglist>(const double *ptr)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>MatrixReadAccess</name>
    <filename>class_matrix_read_access.html</filename>
    <member kind="function">
      <type></type>
      <name>MatrixReadAccess</name>
      <anchorfile>class_matrix_read_access.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(MatrixAliasConstant *mAC)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const double &amp;</type>
      <name>readElement</name>
      <anchorfile>class_matrix_read_access.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>(const unsigned int row, const unsigned int column)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const double &amp;</type>
      <name>readElement</name>
      <anchorfile>class_matrix_read_access.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>(const unsigned int index)</arglist>
    </member>
    <member kind="function">
      <type>const unsigned int</type>
      <name>getRows</name>
      <anchorfile>class_matrix_read_access.html</anchorfile>
      <anchor>a3</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>const unsigned int</type>
      <name>getColumns</name>
      <anchorfile>class_matrix_read_access.html</anchorfile>
      <anchor>a4</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const double *</type>
      <name>getDataPointer</name>
      <anchorfile>class_matrix_read_access.html</anchorfile>
      <anchor>a5</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setDataPointer</name>
      <anchorfile>class_matrix_read_access.html</anchorfile>
      <anchor>a6</anchor>
      <arglist>(const double *data) const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>error</name>
      <anchorfile>class_matrix_read_access.html</anchorfile>
      <anchor>a7</anchor>
      <arglist>(const char *str) const </arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>MatrixAliasConstant *</type>
      <name>m_matrixAliasConstant</name>
      <anchorfile>class_matrix_read_access.html</anchorfile>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>MatrixReadOperator</name>
    <filename>class_matrix_read_operator.html</filename>
    <member kind="function">
      <type></type>
      <name>MatrixReadOperator</name>
      <anchorfile>class_matrix_read_operator.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>MatrixReadOperator</name>
      <anchorfile>class_matrix_read_operator.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>(MatrixAliasConstant *matrixAliasConstant)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>_constructMatrixReadOperator</name>
      <anchorfile>class_matrix_read_operator.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>(MatrixAliasConstant *matrixAliasConstant)</arglist>
    </member>
    <member kind="function">
      <type>const unsigned int</type>
      <name>getRows</name>
      <anchorfile>class_matrix_read_operator.html</anchorfile>
      <anchor>a3</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>const unsigned int</type>
      <name>getColumns</name>
      <anchorfile>class_matrix_read_operator.html</anchorfile>
      <anchor>a4</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>const double *</type>
      <name>getDataPointer</name>
      <anchorfile>class_matrix_read_operator.html</anchorfile>
      <anchor>a5</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>const double &amp;</type>
      <name>element</name>
      <anchorfile>class_matrix_read_operator.html</anchorfile>
      <anchor>a6</anchor>
      <arglist>(const unsigned int row, const unsigned int column) const </arglist>
    </member>
    <member kind="function">
      <type>const double &amp;</type>
      <name>element</name>
      <anchorfile>class_matrix_read_operator.html</anchorfile>
      <anchor>a7</anchor>
      <arglist>(const unsigned int index) const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>error</name>
      <anchorfile>class_matrix_read_operator.html</anchorfile>
      <anchor>a8</anchor>
      <arglist>(const char *str) const </arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>MatrixAliasConstant *</type>
      <name>m_thisMatrix</name>
      <anchorfile>class_matrix_read_operator.html</anchorfile>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>MatrixWriteAccess</name>
    <filename>class_matrix_write_access.html</filename>
    <member kind="function">
      <type></type>
      <name>MatrixWriteAccess</name>
      <anchorfile>class_matrix_write_access.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(MatrixAlias *mA)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual double &amp;</type>
      <name>writeElement</name>
      <anchorfile>class_matrix_write_access.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>(const unsigned int row, const unsigned int column)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual double &amp;</type>
      <name>writeElement</name>
      <anchorfile>class_matrix_write_access.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>(const unsigned int index)</arglist>
    </member>
    <member kind="function">
      <type>const unsigned int</type>
      <name>getRows</name>
      <anchorfile>class_matrix_write_access.html</anchorfile>
      <anchor>a3</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>const unsigned int</type>
      <name>getColumns</name>
      <anchorfile>class_matrix_write_access.html</anchorfile>
      <anchor>a4</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual double *</type>
      <name>getDataPointer</name>
      <anchorfile>class_matrix_write_access.html</anchorfile>
      <anchor>a5</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setDataPointer</name>
      <anchorfile>class_matrix_write_access.html</anchorfile>
      <anchor>a6</anchor>
      <arglist>(const double *data) const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setRows</name>
      <anchorfile>class_matrix_write_access.html</anchorfile>
      <anchor>a7</anchor>
      <arglist>(const unsigned int num) const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setColumns</name>
      <anchorfile>class_matrix_write_access.html</anchorfile>
      <anchor>a8</anchor>
      <arglist>(const unsigned int num) const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>error</name>
      <anchorfile>class_matrix_write_access.html</anchorfile>
      <anchor>a9</anchor>
      <arglist>(const char *str) const </arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>MatrixAlias *</type>
      <name>m_matrixAlias</name>
      <anchorfile>class_matrix_write_access.html</anchorfile>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>MatrixWriteOperator</name>
    <filename>class_matrix_write_operator.html</filename>
    <member kind="function">
      <type></type>
      <name>MatrixWriteOperator</name>
      <anchorfile>class_matrix_write_operator.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>MatrixWriteOperator</name>
      <anchorfile>class_matrix_write_operator.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>(MatrixAlias *matrixAlias)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>_constructMatrixWriteOperator</name>
      <anchorfile>class_matrix_write_operator.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>(MatrixAlias *matrixAlias)</arglist>
    </member>
    <member kind="function">
      <type>const unsigned int</type>
      <name>getRows</name>
      <anchorfile>class_matrix_write_operator.html</anchorfile>
      <anchor>a3</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>const unsigned int</type>
      <name>getColumns</name>
      <anchorfile>class_matrix_write_operator.html</anchorfile>
      <anchor>a4</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>double *</type>
      <name>getDataPointer</name>
      <anchorfile>class_matrix_write_operator.html</anchorfile>
      <anchor>a5</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setDataPointer</name>
      <anchorfile>class_matrix_write_operator.html</anchorfile>
      <anchor>a6</anchor>
      <arglist>(double *data) const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setRows</name>
      <anchorfile>class_matrix_write_operator.html</anchorfile>
      <anchor>a7</anchor>
      <arglist>(const unsigned int num) const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setColumns</name>
      <anchorfile>class_matrix_write_operator.html</anchorfile>
      <anchor>a8</anchor>
      <arglist>(const unsigned int num) const </arglist>
    </member>
    <member kind="function">
      <type>double &amp;</type>
      <name>element</name>
      <anchorfile>class_matrix_write_operator.html</anchorfile>
      <anchor>a9</anchor>
      <arglist>(const unsigned int row, const unsigned int column) const </arglist>
    </member>
    <member kind="function">
      <type>double &amp;</type>
      <name>element</name>
      <anchorfile>class_matrix_write_operator.html</anchorfile>
      <anchor>a10</anchor>
      <arglist>(const unsigned int index) const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>error</name>
      <anchorfile>class_matrix_write_operator.html</anchorfile>
      <anchor>a11</anchor>
      <arglist>(const char *str) const </arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>MatrixAlias *</type>
      <name>m_thisMatrix</name>
      <anchorfile>class_matrix_write_operator.html</anchorfile>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>MRO_Absolute</name>
    <filename>class_m_r_o___absolute.html</filename>
    <base>MatrixReadOperator</base>
    <member kind="function">
      <type>Matrix</type>
      <name>operator()</name>
      <anchorfile>class_m_r_o___absolute.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>() const </arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>MRO_Add</name>
    <filename>class_m_r_o___add.html</filename>
    <base>MatrixReadOperator</base>
    <member kind="function">
      <type>Matrix</type>
      <name>operator()</name>
      <anchorfile>class_m_r_o___add.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(const MatrixAliasConstant &amp;operand) const </arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>MRO_ColumnSum</name>
    <filename>class_m_r_o___column_sum.html</filename>
    <base>MatrixReadOperator</base>
    <member kind="function">
      <type>RowVector</type>
      <name>operator()</name>
      <anchorfile>class_m_r_o___column_sum.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>() const </arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>MRO_Divide</name>
    <filename>class_m_r_o___divide.html</filename>
    <base>MatrixReadOperator</base>
    <member kind="function">
      <type>Matrix</type>
      <name>operator()</name>
      <anchorfile>class_m_r_o___divide.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(const double &amp;operand) const </arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>MRO_Element</name>
    <filename>class_m_r_o___element.html</filename>
    <base>MatrixReadOperator</base>
    <member kind="function">
      <type>const double &amp;</type>
      <name>operator()</name>
      <anchorfile>class_m_r_o___element.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(const unsigned int row, const unsigned int column) const </arglist>
    </member>
    <member kind="function">
      <type>const double &amp;</type>
      <name>operator()</name>
      <anchorfile>class_m_r_o___element.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>(const unsigned int index) const </arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>MRO_ElementMultiply</name>
    <filename>class_m_r_o___element_multiply.html</filename>
    <base>MatrixReadOperator</base>
    <member kind="function">
      <type>Matrix</type>
      <name>operator()</name>
      <anchorfile>class_m_r_o___element_multiply.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(const MatrixAliasConstant &amp;operand) const </arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>MRO_FrobeniusNorm</name>
    <filename>class_m_r_o___frobenius_norm.html</filename>
    <base>MatrixReadOperator</base>
    <member kind="function">
      <type>double</type>
      <name>operator()</name>
      <anchorfile>class_m_r_o___frobenius_norm.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>() const </arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>MRO_InfinityNorm</name>
    <filename>class_m_r_o___infinity_norm.html</filename>
    <base>MatrixReadOperator</base>
    <member kind="function">
      <type>double</type>
      <name>operator()</name>
      <anchorfile>class_m_r_o___infinity_norm.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>() const </arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>MRO_IsColumnVector</name>
    <filename>class_m_r_o___is_column_vector.html</filename>
    <base>MatrixReadOperator</base>
    <member kind="function">
      <type>int</type>
      <name>operator()</name>
      <anchorfile>class_m_r_o___is_column_vector.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>() const </arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>MRO_IsRowVector</name>
    <filename>class_m_r_o___is_row_vector.html</filename>
    <base>MatrixReadOperator</base>
    <member kind="function">
      <type>int</type>
      <name>operator()</name>
      <anchorfile>class_m_r_o___is_row_vector.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>() const </arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>MRO_IsSquareMatrix</name>
    <filename>class_m_r_o___is_square_matrix.html</filename>
    <base>MatrixReadOperator</base>
    <member kind="function">
      <type>int</type>
      <name>operator()</name>
      <anchorfile>class_m_r_o___is_square_matrix.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>() const </arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>MRO_Maximum</name>
    <filename>class_m_r_o___maximum.html</filename>
    <base>MatrixReadOperator</base>
    <member kind="function">
      <type>double</type>
      <name>operator()</name>
      <anchorfile>class_m_r_o___maximum.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>() const </arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>MRO_Minimum</name>
    <filename>class_m_r_o___minimum.html</filename>
    <base>MatrixReadOperator</base>
    <member kind="function">
      <type>double</type>
      <name>operator()</name>
      <anchorfile>class_m_r_o___minimum.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>() const </arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>MRO_Multiply</name>
    <filename>class_m_r_o___multiply.html</filename>
    <base>MatrixReadOperator</base>
    <member kind="function">
      <type>Matrix</type>
      <name>operator()</name>
      <anchorfile>class_m_r_o___multiply.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(const MatrixAliasConstant &amp;operand) const </arglist>
    </member>
    <member kind="function">
      <type>Matrix</type>
      <name>operator()</name>
      <anchorfile>class_m_r_o___multiply.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>(const double &amp;operand) const </arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>MRO_Negative</name>
    <filename>class_m_r_o___negative.html</filename>
    <base>MatrixReadOperator</base>
    <member kind="function">
      <type>Matrix</type>
      <name>operator()</name>
      <anchorfile>class_m_r_o___negative.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>() const </arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>MRO_Print</name>
    <filename>class_m_r_o___print.html</filename>
    <base>MatrixReadOperator</base>
    <member kind="function">
      <type>void</type>
      <name>operator()</name>
      <anchorfile>class_m_r_o___print.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>() const </arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>MRO_PrintMatlabFriendly</name>
    <filename>class_m_r_o___print_matlab_friendly.html</filename>
    <base>MatrixReadOperator</base>
    <member kind="function">
      <type>void</type>
      <name>operator()</name>
      <anchorfile>class_m_r_o___print_matlab_friendly.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>() const </arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>MRO_RowSum</name>
    <filename>class_m_r_o___row_sum.html</filename>
    <base>MatrixReadOperator</base>
    <member kind="function">
      <type>ColumnVector</type>
      <name>operator()</name>
      <anchorfile>class_m_r_o___row_sum.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>() const </arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>MRO_SizeEqual</name>
    <filename>class_m_r_o___size_equal.html</filename>
    <base>MatrixReadOperator</base>
    <member kind="function">
      <type>int</type>
      <name>operator()</name>
      <anchorfile>class_m_r_o___size_equal.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(const MatrixAliasConstant &amp;operand) const </arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>MRO_SquaredElements</name>
    <filename>class_m_r_o___squared_elements.html</filename>
    <base>MatrixReadOperator</base>
    <member kind="function">
      <type>Matrix</type>
      <name>operator()</name>
      <anchorfile>class_m_r_o___squared_elements.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>() const </arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>MRO_SubMatrixAliasConstant</name>
    <filename>class_m_r_o___sub_matrix_alias_constant.html</filename>
    <base>MatrixReadOperator</base>
    <member kind="function">
      <type>SubMatrixAliasConstant</type>
      <name>operator()</name>
      <anchorfile>class_m_r_o___sub_matrix_alias_constant.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(const unsigned int rowStart, const unsigned int rowEnd, const unsigned int columnStart, const unsigned int columnEnd) const </arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>MRO_Subtract</name>
    <filename>class_m_r_o___subtract.html</filename>
    <base>MatrixReadOperator</base>
    <member kind="function">
      <type>Matrix</type>
      <name>operator()</name>
      <anchorfile>class_m_r_o___subtract.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(const MatrixAliasConstant &amp;operand) const </arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>MRO_Transpose</name>
    <filename>class_m_r_o___transpose.html</filename>
    <base>MatrixReadOperator</base>
    <member kind="function">
      <type>Matrix</type>
      <name>operator()</name>
      <anchorfile>class_m_r_o___transpose.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>() const </arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>MWO_Element</name>
    <filename>class_m_w_o___element.html</filename>
    <base>MatrixWriteOperator</base>
    <member kind="function">
      <type>double &amp;</type>
      <name>operator()</name>
      <anchorfile>class_m_w_o___element.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(const unsigned int row, const unsigned int column) const </arglist>
    </member>
    <member kind="function">
      <type>double &amp;</type>
      <name>operator()</name>
      <anchorfile>class_m_w_o___element.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>(const unsigned int index) const </arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>MWO_EqualsElementCopy</name>
    <filename>class_m_w_o___equals_element_copy.html</filename>
    <base>MatrixWriteOperator</base>
    <member kind="function">
      <type>void</type>
      <name>operator()</name>
      <anchorfile>class_m_w_o___equals_element_copy.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(const MatrixAliasConstant &amp;copy) const </arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>MWO_EqualsElementCopyResize</name>
    <filename>class_m_w_o___equals_element_copy_resize.html</filename>
    <base>MatrixWriteOperator</base>
    <member kind="function">
      <type>void</type>
      <name>operator()</name>
      <anchorfile>class_m_w_o___equals_element_copy_resize.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(const MatrixAliasConstant &amp;copy) const </arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>MWO_EqualsMemCopy</name>
    <filename>class_m_w_o___equals_mem_copy.html</filename>
    <base>MatrixWriteOperator</base>
    <member kind="function">
      <type>void</type>
      <name>operator()</name>
      <anchorfile>class_m_w_o___equals_mem_copy.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(const MatrixAliasConstant &amp;copy) const </arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>MWO_EqualsMemCopyResize</name>
    <filename>class_m_w_o___equals_mem_copy_resize.html</filename>
    <base>MatrixWriteOperator</base>
    <member kind="function">
      <type>void</type>
      <name>operator()</name>
      <anchorfile>class_m_w_o___equals_mem_copy_resize.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(const MatrixAliasConstant &amp;copy) const </arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>MWO_Normalise</name>
    <filename>class_m_w_o___normalise.html</filename>
    <base>MatrixWriteOperator</base>
    <member kind="function">
      <type>void</type>
      <name>operator()</name>
      <anchorfile>class_m_w_o___normalise.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>() const </arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>MWO_Randomise</name>
    <filename>class_m_w_o___randomise.html</filename>
    <base>MatrixWriteOperator</base>
    <member kind="function">
      <type>void</type>
      <name>operator()</name>
      <anchorfile>class_m_w_o___randomise.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(const double val) const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>operator()</name>
      <anchorfile>class_m_w_o___randomise.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>() const </arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>MWO_Reshape</name>
    <filename>class_m_w_o___reshape.html</filename>
    <base>MatrixWriteOperator</base>
    <member kind="function">
      <type>void</type>
      <name>operator()</name>
      <anchorfile>class_m_w_o___reshape.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(const unsigned int rows, const unsigned int columns) const </arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>MWO_Resize</name>
    <filename>class_m_w_o___resize.html</filename>
    <base>MatrixWriteOperator</base>
    <member kind="function">
      <type>void</type>
      <name>operator()</name>
      <anchorfile>class_m_w_o___resize.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(const unsigned int rows, const unsigned int columns) const </arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>MWO_Set</name>
    <filename>class_m_w_o___set.html</filename>
    <base>MatrixWriteOperator</base>
    <member kind="function">
      <type>void</type>
      <name>operator()</name>
      <anchorfile>class_m_w_o___set.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(const double val) const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>operator()</name>
      <anchorfile>class_m_w_o___set.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>() const </arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>MWO_SubMatrixAlias</name>
    <filename>class_m_w_o___sub_matrix_alias.html</filename>
    <base>MatrixWriteOperator</base>
    <member kind="function">
      <type>SubMatrixAlias</type>
      <name>operator()</name>
      <anchorfile>class_m_w_o___sub_matrix_alias.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(const unsigned int rowStart, const unsigned int rowEnd, const unsigned int columnStart, const unsigned int columnEnd) const </arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>MWO_Zero</name>
    <filename>class_m_w_o___zero.html</filename>
    <base>MatrixWriteOperator</base>
    <member kind="function">
      <type>void</type>
      <name>operator()</name>
      <anchorfile>class_m_w_o___zero.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>() const </arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>RowVector</name>
    <filename>class_row_vector.html</filename>
    <base>Matrix</base>
    <base>RowVectorAlias</base>
    <member kind="function">
      <type></type>
      <name>RowVector</name>
      <anchorfile>class_row_vector.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>RowVector</name>
      <anchorfile>class_row_vector.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>(const unsigned int size)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>RowVector</name>
      <anchorfile>class_row_vector.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>(const MatrixAliasConstant &amp;copy)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>RowVector</name>
      <anchorfile>class_row_vector.html</anchorfile>
      <anchor>a3</anchor>
      <arglist>(RowVector &amp;copy)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~RowVector</name>
      <anchorfile>class_row_vector.html</anchorfile>
      <anchor>a4</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>RowVector &amp;</type>
      <name>operator=</name>
      <anchorfile>class_row_vector.html</anchorfile>
      <anchor>a5</anchor>
      <arglist>(const MatrixAliasConstant &amp;copy)</arglist>
    </member>
    <member kind="function">
      <type>RowVector &amp;</type>
      <name>operator=</name>
      <anchorfile>class_row_vector.html</anchorfile>
      <anchor>a6</anchor>
      <arglist>(const RowVector &amp;copy)</arglist>
    </member>
    <member kind="variable">
      <type>RVWO_EqualsElementCopyResize</type>
      <name>equals</name>
      <anchorfile>class_row_vector.html</anchorfile>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>RVWO_Resize</type>
      <name>resize</name>
      <anchorfile>class_row_vector.html</anchorfile>
      <anchor>o1</anchor>
      <arglist></arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>_constructRowVector</name>
      <anchorfile>class_row_vector.html</anchorfile>
      <anchor>b0</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>_constructRowVector</name>
      <anchorfile>class_row_vector.html</anchorfile>
      <anchor>b1</anchor>
      <arglist>(const MatrixAliasConstant &amp;copy)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>RowVectorAlias</name>
    <filename>class_row_vector_alias.html</filename>
    <base>RowVectorAliasConstant</base>
    <base virtualness="virtual">MatrixAlias</base>
    <member kind="function">
      <type></type>
      <name>RowVectorAlias</name>
      <anchorfile>class_row_vector_alias.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(const double *data, const unsigned int size)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>RowVectorAlias</name>
      <anchorfile>class_row_vector_alias.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>(const MatrixAliasConstant *alias)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>RowVectorAlias</name>
      <anchorfile>class_row_vector_alias.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>(const MatrixAliasConstant &amp;copy)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>RowVectorAlias</name>
      <anchorfile>class_row_vector_alias.html</anchorfile>
      <anchor>a3</anchor>
      <arglist>(const RowVectorAlias &amp;copy)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~RowVectorAlias</name>
      <anchorfile>class_row_vector_alias.html</anchorfile>
      <anchor>a4</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>RowVectorAlias &amp;</type>
      <name>operator=</name>
      <anchorfile>class_row_vector_alias.html</anchorfile>
      <anchor>a5</anchor>
      <arglist>(const MatrixAliasConstant &amp;copy)</arglist>
    </member>
    <member kind="function">
      <type>RowVectorAlias &amp;</type>
      <name>operator=</name>
      <anchorfile>class_row_vector_alias.html</anchorfile>
      <anchor>a6</anchor>
      <arglist>(const RowVectorAlias &amp;copy)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>_constructRowVectorAlias</name>
      <anchorfile>class_row_vector_alias.html</anchorfile>
      <anchor>b0</anchor>
      <arglist>()</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>RowVectorAliasConstant</name>
    <filename>class_row_vector_alias_constant.html</filename>
    <base virtualness="virtual">MatrixAliasConstant</base>
    <member kind="function">
      <type></type>
      <name>RowVectorAliasConstant</name>
      <anchorfile>class_row_vector_alias_constant.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(const double *data, const unsigned int size)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>RowVectorAliasConstant</name>
      <anchorfile>class_row_vector_alias_constant.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>(const MatrixAliasConstant *alias)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>RowVectorAliasConstant</name>
      <anchorfile>class_row_vector_alias_constant.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>(const MatrixAliasConstant &amp;copy)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>RowVectorAliasConstant</name>
      <anchorfile>class_row_vector_alias_constant.html</anchorfile>
      <anchor>a3</anchor>
      <arglist>(const RowVectorAliasConstant &amp;copy)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~RowVectorAliasConstant</name>
      <anchorfile>class_row_vector_alias_constant.html</anchorfile>
      <anchor>a4</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>RowVectorAliasConstant &amp;</type>
      <name>operator=</name>
      <anchorfile>class_row_vector_alias_constant.html</anchorfile>
      <anchor>a5</anchor>
      <arglist>(const MatrixAliasConstant &amp;copy)</arglist>
    </member>
    <member kind="function">
      <type>RowVectorAliasConstant &amp;</type>
      <name>operator=</name>
      <anchorfile>class_row_vector_alias_constant.html</anchorfile>
      <anchor>a6</anchor>
      <arglist>(const RowVectorAliasConstant &amp;copy)</arglist>
    </member>
    <member kind="variable">
      <type>RVRO_CrossProduct</type>
      <name>cross</name>
      <anchorfile>class_row_vector_alias_constant.html</anchorfile>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>RVRO_DotProduct</type>
      <name>dot</name>
      <anchorfile>class_row_vector_alias_constant.html</anchorfile>
      <anchor>o1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>RVRO_Direction</type>
      <name>direction</name>
      <anchorfile>class_row_vector_alias_constant.html</anchorfile>
      <anchor>o2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>RVRO_GetSize</type>
      <name>getSize</name>
      <anchorfile>class_row_vector_alias_constant.html</anchorfile>
      <anchor>o3</anchor>
      <arglist></arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>_constructRowVectorAliasConstant</name>
      <anchorfile>class_row_vector_alias_constant.html</anchorfile>
      <anchor>b0</anchor>
      <arglist>()</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>RowVectorReadOperator</name>
    <filename>class_row_vector_read_operator.html</filename>
    <base>MatrixReadOperator</base>
    <member kind="function">
      <type></type>
      <name>RowVectorReadOperator</name>
      <anchorfile>class_row_vector_read_operator.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>RowVectorReadOperator</name>
      <anchorfile>class_row_vector_read_operator.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>(RowVectorAliasConstant *rowVectorAliasConstant)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>_constructRowVectorReadOperator</name>
      <anchorfile>class_row_vector_read_operator.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>(RowVectorAliasConstant *rowVectorAliasConstant)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>RowVectorAliasConstant *</type>
      <name>m_thisMatrix</name>
      <anchorfile>class_row_vector_read_operator.html</anchorfile>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>RowVectorWriteOperator</name>
    <filename>class_row_vector_write_operator.html</filename>
    <base>MatrixWriteOperator</base>
    <member kind="function">
      <type></type>
      <name>RowVectorWriteOperator</name>
      <anchorfile>class_row_vector_write_operator.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>RowVectorWriteOperator</name>
      <anchorfile>class_row_vector_write_operator.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>(RowVectorAlias *rowVectorAlias)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>_constructRowVectorWriteOperator</name>
      <anchorfile>class_row_vector_write_operator.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>(RowVectorAlias *rowVectorAlias)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>RowVectorAlias *</type>
      <name>m_thisMatrix</name>
      <anchorfile>class_row_vector_write_operator.html</anchorfile>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>RVRO_CrossProduct</name>
    <filename>class_r_v_r_o___cross_product.html</filename>
    <base>RowVectorReadOperator</base>
    <member kind="function">
      <type>RowVector</type>
      <name>operator()</name>
      <anchorfile>class_r_v_r_o___cross_product.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(const RowVectorAliasConstant &amp;operand) const </arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>RVRO_Direction</name>
    <filename>class_r_v_r_o___direction.html</filename>
    <base>RowVectorReadOperator</base>
    <member kind="function">
      <type>RowVector</type>
      <name>operator()</name>
      <anchorfile>class_r_v_r_o___direction.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>() const </arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>RVRO_DotProduct</name>
    <filename>class_r_v_r_o___dot_product.html</filename>
    <base>RowVectorReadOperator</base>
    <member kind="function">
      <type>double</type>
      <name>operator()</name>
      <anchorfile>class_r_v_r_o___dot_product.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(const RowVectorAliasConstant &amp;operand) const </arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>RVRO_GetSize</name>
    <filename>class_r_v_r_o___get_size.html</filename>
    <base>RowVectorReadOperator</base>
    <member kind="function">
      <type>const unsigned int</type>
      <name>operator()</name>
      <anchorfile>class_r_v_r_o___get_size.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>() const </arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>RVWO_EqualsElementCopyResize</name>
    <filename>class_r_v_w_o___equals_element_copy_resize.html</filename>
    <base>RowVectorWriteOperator</base>
    <member kind="function">
      <type>void</type>
      <name>operator()</name>
      <anchorfile>class_r_v_w_o___equals_element_copy_resize.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(const MatrixAliasConstant &amp;copy) const </arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>RVWO_Resize</name>
    <filename>class_r_v_w_o___resize.html</filename>
    <base>RowVectorWriteOperator</base>
    <member kind="function">
      <type>void</type>
      <name>operator()</name>
      <anchorfile>class_r_v_w_o___resize.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(const unsigned int size) const </arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>SqMRO_Cofactor</name>
    <filename>class_sq_m_r_o___cofactor.html</filename>
    <base>SquareMatrixReadOperator</base>
    <member kind="function">
      <type>double</type>
      <name>operator()</name>
      <anchorfile>class_sq_m_r_o___cofactor.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(const unsigned int row, const unsigned int column) const </arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>SqMRO_DeterminantBasic</name>
    <filename>class_sq_m_r_o___determinant_basic.html</filename>
    <base>SquareMatrixReadOperator</base>
    <member kind="function">
      <type>double</type>
      <name>operator()</name>
      <anchorfile>class_sq_m_r_o___determinant_basic.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>() const </arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>SqMRO_DeterminantLUDecomp</name>
    <filename>class_sq_m_r_o___determinant_l_u_decomp.html</filename>
    <base>SquareMatrixReadOperator</base>
    <member kind="function">
      <type>double</type>
      <name>operator()</name>
      <anchorfile>class_sq_m_r_o___determinant_l_u_decomp.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>() const </arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>SqMRO_Exponential</name>
    <filename>class_sq_m_r_o___exponential.html</filename>
    <base>SquareMatrixReadOperator</base>
    <member kind="function">
      <type>SquareMatrix</type>
      <name>operator()</name>
      <anchorfile>class_sq_m_r_o___exponential.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(double time) const </arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>SqMRO_InverseBasic</name>
    <filename>class_sq_m_r_o___inverse_basic.html</filename>
    <base>SquareMatrixReadOperator</base>
    <member kind="function">
      <type>SquareMatrix</type>
      <name>operator()</name>
      <anchorfile>class_sq_m_r_o___inverse_basic.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>() const </arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>SqMRO_InverseLUDecomp</name>
    <filename>class_sq_m_r_o___inverse_l_u_decomp.html</filename>
    <base>SquareMatrixReadOperator</base>
    <member kind="function">
      <type>SquareMatrix</type>
      <name>operator()</name>
      <anchorfile>class_sq_m_r_o___inverse_l_u_decomp.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>() const </arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>SqMRO_LUBackSubstitution</name>
    <filename>class_sq_m_r_o___l_u_back_substitution.html</filename>
    <base>SquareMatrixReadOperator</base>
    <member kind="function">
      <type>SquareMatrix</type>
      <name>operator()</name>
      <anchorfile>class_sq_m_r_o___l_u_back_substitution.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(RowVector &amp;indx, RowVector &amp;b) const </arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>SqMRO_LUDecomposition</name>
    <filename>class_sq_m_r_o___l_u_decomposition.html</filename>
    <base>SquareMatrixReadOperator</base>
    <member kind="function">
      <type>SquareMatrix</type>
      <name>operator()</name>
      <anchorfile>class_sq_m_r_o___l_u_decomposition.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(RowVector &amp;indx, double *d) const </arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>SqMWO_DirectionCosine</name>
    <filename>class_sq_m_w_o___direction_cosine.html</filename>
    <base>SquareMatrixWriteOperator</base>
    <member kind="function">
      <type>void</type>
      <name>operator()</name>
      <anchorfile>class_sq_m_w_o___direction_cosine.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(ColumnVectorAlias attitude)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>operator()</name>
      <anchorfile>class_sq_m_w_o___direction_cosine.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>(double phi, double theta, double psi)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>SqMWO_EqualsElementCopyResize</name>
    <filename>class_sq_m_w_o___equals_element_copy_resize.html</filename>
    <base>SquareMatrixWriteOperator</base>
    <member kind="function">
      <type>void</type>
      <name>operator()</name>
      <anchorfile>class_sq_m_w_o___equals_element_copy_resize.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(const MatrixAliasConstant &amp;copy) const </arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>SqMWO_Identity</name>
    <filename>class_sq_m_w_o___identity.html</filename>
    <base>SquareMatrixWriteOperator</base>
    <member kind="function">
      <type>void</type>
      <name>operator()</name>
      <anchorfile>class_sq_m_w_o___identity.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>() const </arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>SqMWO_Resize</name>
    <filename>class_sq_m_w_o___resize.html</filename>
    <base>SquareMatrixWriteOperator</base>
    <member kind="function">
      <type>void</type>
      <name>operator()</name>
      <anchorfile>class_sq_m_w_o___resize.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(const unsigned int size) const </arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>SquareMatrix</name>
    <filename>class_square_matrix.html</filename>
    <base>Matrix</base>
    <base>SquareMatrixAlias</base>
    <member kind="function">
      <type></type>
      <name>SquareMatrix</name>
      <anchorfile>class_square_matrix.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>SquareMatrix</name>
      <anchorfile>class_square_matrix.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>(const unsigned int size)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>SquareMatrix</name>
      <anchorfile>class_square_matrix.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>(const MatrixAliasConstant &amp;copy)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>SquareMatrix</name>
      <anchorfile>class_square_matrix.html</anchorfile>
      <anchor>a3</anchor>
      <arglist>(const SquareMatrix &amp;copy)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~SquareMatrix</name>
      <anchorfile>class_square_matrix.html</anchorfile>
      <anchor>a4</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>SquareMatrix &amp;</type>
      <name>operator=</name>
      <anchorfile>class_square_matrix.html</anchorfile>
      <anchor>a5</anchor>
      <arglist>(const MatrixAliasConstant &amp;copy)</arglist>
    </member>
    <member kind="function">
      <type>SquareMatrix &amp;</type>
      <name>operator=</name>
      <anchorfile>class_square_matrix.html</anchorfile>
      <anchor>a6</anchor>
      <arglist>(const SquareMatrix &amp;copy)</arglist>
    </member>
    <member kind="variable">
      <type>SqMWO_EqualsElementCopyResize</type>
      <name>equals</name>
      <anchorfile>class_square_matrix.html</anchorfile>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>SqMWO_Resize</type>
      <name>resize</name>
      <anchorfile>class_square_matrix.html</anchorfile>
      <anchor>o1</anchor>
      <arglist></arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>_constructSquareMatrix</name>
      <anchorfile>class_square_matrix.html</anchorfile>
      <anchor>b0</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>_constructSquareMatrix</name>
      <anchorfile>class_square_matrix.html</anchorfile>
      <anchor>b1</anchor>
      <arglist>(const MatrixAliasConstant &amp;copy)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>SquareMatrixAlias</name>
    <filename>class_square_matrix_alias.html</filename>
    <base virtualness="virtual">MatrixAlias</base>
    <base>SquareMatrixAliasConstant</base>
    <member kind="function">
      <type></type>
      <name>SquareMatrixAlias</name>
      <anchorfile>class_square_matrix_alias.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(const double *data, const unsigned int size)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>SquareMatrixAlias</name>
      <anchorfile>class_square_matrix_alias.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>(const MatrixAliasConstant *alias)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>SquareMatrixAlias</name>
      <anchorfile>class_square_matrix_alias.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>(const MatrixAliasConstant &amp;copy)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>SquareMatrixAlias</name>
      <anchorfile>class_square_matrix_alias.html</anchorfile>
      <anchor>a3</anchor>
      <arglist>(const SquareMatrixAlias &amp;copy)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~SquareMatrixAlias</name>
      <anchorfile>class_square_matrix_alias.html</anchorfile>
      <anchor>a4</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>SquareMatrixAlias &amp;</type>
      <name>operator=</name>
      <anchorfile>class_square_matrix_alias.html</anchorfile>
      <anchor>a5</anchor>
      <arglist>(const MatrixAliasConstant &amp;copy)</arglist>
    </member>
    <member kind="function">
      <type>SquareMatrixAlias &amp;</type>
      <name>operator=</name>
      <anchorfile>class_square_matrix_alias.html</anchorfile>
      <anchor>a6</anchor>
      <arglist>(const SquareMatrixAlias &amp;copy)</arglist>
    </member>
    <member kind="variable">
      <type>SqMWO_Identity</type>
      <name>identity</name>
      <anchorfile>class_square_matrix_alias.html</anchorfile>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>SqMWO_DirectionCosine</type>
      <name>directionCosine</name>
      <anchorfile>class_square_matrix_alias.html</anchorfile>
      <anchor>o1</anchor>
      <arglist></arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>_constructSquareMatrixAlias</name>
      <anchorfile>class_square_matrix_alias.html</anchorfile>
      <anchor>b0</anchor>
      <arglist>()</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>SquareMatrixAliasConstant</name>
    <filename>class_square_matrix_alias_constant.html</filename>
    <base virtualness="virtual">MatrixAliasConstant</base>
    <member kind="function">
      <type></type>
      <name>SquareMatrixAliasConstant</name>
      <anchorfile>class_square_matrix_alias_constant.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(const double *data, const unsigned int size)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>SquareMatrixAliasConstant</name>
      <anchorfile>class_square_matrix_alias_constant.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>(const MatrixAliasConstant *alias)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>SquareMatrixAliasConstant</name>
      <anchorfile>class_square_matrix_alias_constant.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>(const MatrixAliasConstant &amp;copy)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>SquareMatrixAliasConstant</name>
      <anchorfile>class_square_matrix_alias_constant.html</anchorfile>
      <anchor>a3</anchor>
      <arglist>(const SquareMatrixAliasConstant &amp;copy)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~SquareMatrixAliasConstant</name>
      <anchorfile>class_square_matrix_alias_constant.html</anchorfile>
      <anchor>a4</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>SquareMatrixAliasConstant &amp;</type>
      <name>operator=</name>
      <anchorfile>class_square_matrix_alias_constant.html</anchorfile>
      <anchor>a5</anchor>
      <arglist>(const MatrixAliasConstant &amp;copy)</arglist>
    </member>
    <member kind="function">
      <type>SquareMatrixAliasConstant &amp;</type>
      <name>operator=</name>
      <anchorfile>class_square_matrix_alias_constant.html</anchorfile>
      <anchor>a6</anchor>
      <arglist>(const SquareMatrixAliasConstant &amp;copy)</arglist>
    </member>
    <member kind="variable">
      <type>SqMRO_DeterminantLUDecomp</type>
      <name>determinant</name>
      <anchorfile>class_square_matrix_alias_constant.html</anchorfile>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>SqMRO_DeterminantBasic</type>
      <name>determinant2</name>
      <anchorfile>class_square_matrix_alias_constant.html</anchorfile>
      <anchor>o1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>SqMRO_Cofactor</type>
      <name>cofactor</name>
      <anchorfile>class_square_matrix_alias_constant.html</anchorfile>
      <anchor>o2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>SqMRO_InverseLUDecomp</type>
      <name>inverse</name>
      <anchorfile>class_square_matrix_alias_constant.html</anchorfile>
      <anchor>o3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>SqMRO_InverseBasic</type>
      <name>inverse2</name>
      <anchorfile>class_square_matrix_alias_constant.html</anchorfile>
      <anchor>o4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>SqMRO_Exponential</type>
      <name>exponential</name>
      <anchorfile>class_square_matrix_alias_constant.html</anchorfile>
      <anchor>o5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>SqMRO_LUDecomposition</type>
      <name>luDecomposition</name>
      <anchorfile>class_square_matrix_alias_constant.html</anchorfile>
      <anchor>o6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>SqMRO_LUBackSubstitution</type>
      <name>luBackSubstitution</name>
      <anchorfile>class_square_matrix_alias_constant.html</anchorfile>
      <anchor>o7</anchor>
      <arglist></arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>_constructSquareMatrixAliasConstant</name>
      <anchorfile>class_square_matrix_alias_constant.html</anchorfile>
      <anchor>b0</anchor>
      <arglist>()</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>SquareMatrixReadOperator</name>
    <filename>class_square_matrix_read_operator.html</filename>
    <base>MatrixReadOperator</base>
    <member kind="function">
      <type></type>
      <name>SquareMatrixReadOperator</name>
      <anchorfile>class_square_matrix_read_operator.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>SquareMatrixReadOperator</name>
      <anchorfile>class_square_matrix_read_operator.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>(SquareMatrixAliasConstant *squareMatrixAliasConstant)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>_constructSquareMatrixReadOperator</name>
      <anchorfile>class_square_matrix_read_operator.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>(SquareMatrixAliasConstant *squareMatrixAliasConstant)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>SquareMatrixAliasConstant *</type>
      <name>m_thisMatrix</name>
      <anchorfile>class_square_matrix_read_operator.html</anchorfile>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>SquareMatrixWriteOperator</name>
    <filename>class_square_matrix_write_operator.html</filename>
    <base>MatrixWriteOperator</base>
    <member kind="function">
      <type></type>
      <name>SquareMatrixWriteOperator</name>
      <anchorfile>class_square_matrix_write_operator.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>SquareMatrixWriteOperator</name>
      <anchorfile>class_square_matrix_write_operator.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>(SquareMatrixAlias *squareMatrixAlias)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>_constructSquareMatrixWriteOperator</name>
      <anchorfile>class_square_matrix_write_operator.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>(SquareMatrixAlias *squareMatrixAlias)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>SquareMatrixAlias *</type>
      <name>m_thisMatrix</name>
      <anchorfile>class_square_matrix_write_operator.html</anchorfile>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>SubMatrixAlias</name>
    <filename>class_sub_matrix_alias.html</filename>
    <base>SubMatrixAliasConstant</base>
    <base>MatrixAlias</base>
    <member kind="function">
      <type></type>
      <name>SubMatrixAlias</name>
      <anchorfile>class_sub_matrix_alias.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(const MatrixAliasConstant *original, const unsigned int rowStart, const unsigned int rowEnd, const unsigned int columnStart, const unsigned int columnEnd)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>SubMatrixAlias</name>
      <anchorfile>class_sub_matrix_alias.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>(const MatrixAliasConstant &amp;original, const unsigned int rowStart, const unsigned int rowEnd, const unsigned int columnStart, const unsigned int columnEnd)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>SubMatrixAlias</name>
      <anchorfile>class_sub_matrix_alias.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>(const SubMatrixAlias &amp;copy)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~SubMatrixAlias</name>
      <anchorfile>class_sub_matrix_alias.html</anchorfile>
      <anchor>a3</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>SubMatrixAlias &amp;</type>
      <name>operator=</name>
      <anchorfile>class_sub_matrix_alias.html</anchorfile>
      <anchor>a4</anchor>
      <arglist>(const MatrixAliasConstant &amp;copy)</arglist>
    </member>
    <member kind="function">
      <type>SubMatrixAlias &amp;</type>
      <name>operator=</name>
      <anchorfile>class_sub_matrix_alias.html</anchorfile>
      <anchor>a5</anchor>
      <arglist>(const SubMatrixAlias &amp;copy)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>_constructSubMatrixAlias</name>
      <anchorfile>class_sub_matrix_alias.html</anchorfile>
      <anchor>b0</anchor>
      <arglist>()</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>SubMatrixAliasConstant</name>
    <filename>class_sub_matrix_alias_constant.html</filename>
    <base virtualness="virtual">MatrixAliasConstant</base>
    <member kind="function">
      <type></type>
      <name>SubMatrixAliasConstant</name>
      <anchorfile>class_sub_matrix_alias_constant.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(const MatrixAliasConstant *original, const unsigned int rowStart, const unsigned int rowEnd, const unsigned int columnStart, const unsigned int columnEnd)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>SubMatrixAliasConstant</name>
      <anchorfile>class_sub_matrix_alias_constant.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>(const MatrixAliasConstant &amp;original, const unsigned int rowStart, const unsigned int rowEnd, const unsigned int columnStart, const unsigned int columnEnd)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>SubMatrixAliasConstant</name>
      <anchorfile>class_sub_matrix_alias_constant.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>(const SubMatrixAliasConstant &amp;copy)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~SubMatrixAliasConstant</name>
      <anchorfile>class_sub_matrix_alias_constant.html</anchorfile>
      <anchor>a3</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>SubMatrixAliasConstant &amp;</type>
      <name>operator=</name>
      <anchorfile>class_sub_matrix_alias_constant.html</anchorfile>
      <anchor>a4</anchor>
      <arglist>(const MatrixAliasConstant &amp;copy)</arglist>
    </member>
    <member kind="function">
      <type>SubMatrixAliasConstant &amp;</type>
      <name>operator=</name>
      <anchorfile>class_sub_matrix_alias_constant.html</anchorfile>
      <anchor>a5</anchor>
      <arglist>(const SubMatrixAliasConstant &amp;copy)</arglist>
    </member>
    <member kind="variable">
      <type>SubMatrixContainer *</type>
      <name>m_subMatrixContainer</name>
      <anchorfile>class_sub_matrix_alias_constant.html</anchorfile>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>_constructSubMatrixAliasConstant</name>
      <anchorfile>class_sub_matrix_alias_constant.html</anchorfile>
      <anchor>b0</anchor>
      <arglist>()</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>SubMatrixContainer</name>
    <filename>class_sub_matrix_container.html</filename>
    <base>MatrixContainer</base>
    <member kind="function">
      <type></type>
      <name>SubMatrixContainer</name>
      <anchorfile>class_sub_matrix_container.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(const MatrixContainer *original, unsigned int rowStart, unsigned int rowEnd, unsigned int columnStart, unsigned int columnEnd)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>SubMatrixContainer</name>
      <anchorfile>class_sub_matrix_container.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>(const SubMatrixContainer &amp;copy)</arglist>
    </member>
    <member kind="function">
      <type>const MatrixContainer *</type>
      <name>getOrigPointer</name>
      <anchorfile>class_sub_matrix_container.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>unsigned int</type>
      <name>getRowsOrig</name>
      <anchorfile>class_sub_matrix_container.html</anchorfile>
      <anchor>a3</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>unsigned int</type>
      <name>getColumnsOrig</name>
      <anchorfile>class_sub_matrix_container.html</anchorfile>
      <anchor>a4</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>unsigned int</type>
      <name>getRowStart</name>
      <anchorfile>class_sub_matrix_container.html</anchorfile>
      <anchor>a5</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>unsigned int</type>
      <name>getRowEnd</name>
      <anchorfile>class_sub_matrix_container.html</anchorfile>
      <anchor>a6</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>unsigned int</type>
      <name>getColumnStart</name>
      <anchorfile>class_sub_matrix_container.html</anchorfile>
      <anchor>a7</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>unsigned int</type>
      <name>getColumnEnd</name>
      <anchorfile>class_sub_matrix_container.html</anchorfile>
      <anchor>a8</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setRowStart</name>
      <anchorfile>class_sub_matrix_container.html</anchorfile>
      <anchor>a9</anchor>
      <arglist>(const unsigned int num)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setRowEnd</name>
      <anchorfile>class_sub_matrix_container.html</anchorfile>
      <anchor>a10</anchor>
      <arglist>(const unsigned int num)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setColumnStart</name>
      <anchorfile>class_sub_matrix_container.html</anchorfile>
      <anchor>a11</anchor>
      <arglist>(const unsigned int num)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setColumnEnd</name>
      <anchorfile>class_sub_matrix_container.html</anchorfile>
      <anchor>a12</anchor>
      <arglist>(const unsigned int num)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>SubMatrixReadAccess</name>
    <filename>class_sub_matrix_read_access.html</filename>
    <base>MatrixReadAccess</base>
    <member kind="function">
      <type></type>
      <name>SubMatrixReadAccess</name>
      <anchorfile>class_sub_matrix_read_access.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(SubMatrixAliasConstant *sMAC)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const double &amp;</type>
      <name>readElement</name>
      <anchorfile>class_sub_matrix_read_access.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>(const unsigned int row, const unsigned int column)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const double &amp;</type>
      <name>readElement</name>
      <anchorfile>class_sub_matrix_read_access.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>(const unsigned int index)</arglist>
    </member>
    <member kind="function">
      <type>const unsigned int</type>
      <name>getRowsOrig</name>
      <anchorfile>class_sub_matrix_read_access.html</anchorfile>
      <anchor>a3</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>const unsigned int</type>
      <name>getColumnsOrig</name>
      <anchorfile>class_sub_matrix_read_access.html</anchorfile>
      <anchor>a4</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>const unsigned int</type>
      <name>getRowStart</name>
      <anchorfile>class_sub_matrix_read_access.html</anchorfile>
      <anchor>a5</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>const unsigned int</type>
      <name>getRowEnd</name>
      <anchorfile>class_sub_matrix_read_access.html</anchorfile>
      <anchor>a6</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>const unsigned int</type>
      <name>getColumnStart</name>
      <anchorfile>class_sub_matrix_read_access.html</anchorfile>
      <anchor>a7</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>const unsigned int</type>
      <name>getColumnEnd</name>
      <anchorfile>class_sub_matrix_read_access.html</anchorfile>
      <anchor>a8</anchor>
      <arglist>() const </arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>SubMatrixWriteAccess</name>
    <filename>class_sub_matrix_write_access.html</filename>
    <base>MatrixWriteAccess</base>
    <member kind="function">
      <type></type>
      <name>SubMatrixWriteAccess</name>
      <anchorfile>class_sub_matrix_write_access.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(SubMatrixAlias *sMA)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual double &amp;</type>
      <name>writeElement</name>
      <anchorfile>class_sub_matrix_write_access.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>(const unsigned int row, const unsigned int column)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual double &amp;</type>
      <name>writeElement</name>
      <anchorfile>class_sub_matrix_write_access.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>(const unsigned int index)</arglist>
    </member>
    <member kind="function">
      <type>const unsigned int</type>
      <name>getRowsOrig</name>
      <anchorfile>class_sub_matrix_write_access.html</anchorfile>
      <anchor>a3</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>const unsigned int</type>
      <name>getColumnsOrig</name>
      <anchorfile>class_sub_matrix_write_access.html</anchorfile>
      <anchor>a4</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>const unsigned int</type>
      <name>getRowStart</name>
      <anchorfile>class_sub_matrix_write_access.html</anchorfile>
      <anchor>a5</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>const unsigned int</type>
      <name>getRowEnd</name>
      <anchorfile>class_sub_matrix_write_access.html</anchorfile>
      <anchor>a6</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>const unsigned int</type>
      <name>getColumnStart</name>
      <anchorfile>class_sub_matrix_write_access.html</anchorfile>
      <anchor>a7</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>const unsigned int</type>
      <name>getColumnEnd</name>
      <anchorfile>class_sub_matrix_write_access.html</anchorfile>
      <anchor>a8</anchor>
      <arglist>() const </arglist>
    </member>
  </compound>
  <compound kind="dir">
    <name>C:/Code/lib/MatrixClassLib/code/</name>
    <path>C:/Code/lib/MatrixClassLib/code/</path>
    <filename>dir_000003.html</filename>
    <dir>C:/Code/lib/MatrixClassLib/code/include/</dir>
    <dir>C:/Code/lib/MatrixClassLib/code/src/</dir>
  </compound>
  <compound kind="dir">
    <name>C:/Code/</name>
    <path>C:/Code/</path>
    <filename>dir_000000.html</filename>
    <dir>C:/Code/lib/</dir>
  </compound>
  <compound kind="dir">
    <name>C:/Code/lib/MatrixClassLib/code/include/</name>
    <path>C:/Code/lib/MatrixClassLib/code/include/</path>
    <filename>dir_000004.html</filename>
    <file>matrix.h</file>
    <file>matrix_access.h</file>
    <file>matrix_container.h</file>
    <file>matrix_operator.h</file>
  </compound>
  <compound kind="dir">
    <name>C:/Code/lib/</name>
    <path>C:/Code/lib/</path>
    <filename>dir_000001.html</filename>
    <dir>C:/Code/lib/MatrixClassLib/</dir>
  </compound>
  <compound kind="dir">
    <name>C:/Code/lib/MatrixClassLib/</name>
    <path>C:/Code/lib/MatrixClassLib/</path>
    <filename>dir_000002.html</filename>
    <dir>C:/Code/lib/MatrixClassLib/code/</dir>
  </compound>
  <compound kind="dir">
    <name>C:/Code/lib/MatrixClassLib/code/src/</name>
    <path>C:/Code/lib/MatrixClassLib/code/src/</path>
    <filename>dir_000005.html</filename>
    <file>matrix.cpp</file>
    <file>matrix_access.cpp</file>
    <file>matrix_operator.cpp</file>
  </compound>
</tagfile>
