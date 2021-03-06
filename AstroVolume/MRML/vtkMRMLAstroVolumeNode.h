/*==============================================================================

  Copyright (c) Kapteyn Astronomical Institute
  University of Groningen, Groningen, Netherlands. All Rights Reserved.

  See COPYRIGHT.txt
  or http://www.slicer.org/copyright/copyright.txt for details.

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

  This file was originally developed by Davide Punzo, Kapteyn Astronomical Institute,
  and was supported through the European Research Consil grant nr. 291531.

==============================================================================*/

#ifndef __vtkMRMLAstroVolumeNode_h
#define __vtkMRMLAstroVolumeNode_h


// MRML includes
#include <vtkMRML.h>
#include <vtkMRMLScalarVolumeNode.h>
#include <vtkMRMLScene.h>

// VTK includes
#include <vtkDoubleArray.h>
#include <vtkSmartPointer.h>

#include <vtkSlicerAstroVolumeModuleMRMLExport.h>

class vtkMRMLAstroVolumeDisplayNode;
class vtkMRMLAstroLabelMapVolumeNode;

/// \ingroup Slicer_QtModules_AstroVolumeNode
class VTK_MRML_ASTRO_EXPORT vtkMRMLAstroVolumeNode : public vtkMRMLScalarVolumeNode
{
  public:

  static vtkMRMLAstroVolumeNode *New();
  vtkTypeMacro(vtkMRMLAstroVolumeNode,vtkMRMLScalarVolumeNode);
  void PrintSelf(ostream& os, vtkIndent indent);

  virtual vtkMRMLNode* CreateNodeInstance();

  ///
  /// Set node attributes
  virtual void ReadXMLAttributes( const char** atts);

  ///
  /// Write this node's information to a MRML file in XML format.
  virtual void WriteXML(ostream& of, int indent);

  ///
  /// Copy the node's attributes to this object
  virtual void Copy(vtkMRMLNode *node);

  ///
  /// Get node XML tag name (like Volume, Model)
  virtual const char* GetNodeTagName() {return "AstroVolume";};

  ///
  /// Make a 'None' volume node with blank image data
  static void CreateNoneNode(vtkMRMLScene *scene);

  ///
  /// Create and return default Storage node
  virtual vtkMRMLStorageNode* CreateDefaultStorageNode();

  ///
  /// Create and observe default display node
  virtual void CreateDefaultDisplayNodes();
  
  ///
  /// Get AstroVolume display node
  virtual vtkMRMLAstroVolumeDisplayNode* GetAstroVolumeDisplayNode();

  ///
  /// Update Max and Min Attributes
  virtual void UpdateRangeAttributes();

  ///
  /// Update Noise Attribute
   virtual void UpdateNoiseAttributes();

protected:
  vtkMRMLAstroVolumeNode();
  virtual ~vtkMRMLAstroVolumeNode();

  vtkMRMLAstroVolumeNode(const vtkMRMLAstroVolumeNode&);
  void operator=(const vtkMRMLAstroVolumeNode&);
};

#endif
