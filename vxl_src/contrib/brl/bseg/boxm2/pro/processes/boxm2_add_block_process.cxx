// This is brl/bseg/boxm2/pro/processes/boxm2_add_block_process.cxx
#include <bprb/bprb_func_process.h>
//:
// \file
// \brief  A process for creating a scene
//
// \author Vishal Jain
// \date Mar 15, 2011

#include <vcl_fstream.h>
#include <boxm2/boxm2_scene.h>

namespace boxm2_add_block_process_globals
{
  const unsigned n_inputs_  = 15;
  const unsigned n_outputs_ = 0;
}

bool boxm2_add_block_process_cons(bprb_func_process& pro)
{
  using namespace boxm2_add_block_process_globals;

  //process takes 2 inputs
  vcl_vector<vcl_string> input_types_(n_inputs_);
  input_types_[0]  = "boxm2_scene_sptr";
  input_types_[1]  = "int";
  input_types_[2]  = "int";
  input_types_[3]  = "int";
  input_types_[4]  = "unsigned";
  input_types_[5]  = "unsigned";
  input_types_[6]  = "unsigned";
  input_types_[7]  = "unsigned"; // maximum tree depth
  input_types_[8]  = "float";    // local origin x
  input_types_[9]  = "float";    // local origin y
  input_types_[10]  = "float";    // local origin z
  input_types_[11] = "float";    // block dims
  input_types_[12] = "float";    // max_mb
  input_types_[13] = "float";    // p_init
  input_types_[14]  = "unsigned"; // init tree depth

  // process has 1 output
  vcl_vector<vcl_string> output_types_(n_outputs_);

  return pro.set_input_types(input_types_) && pro.set_output_types(output_types_);
}

bool boxm2_add_block_process(bprb_func_process& pro)
{
  using namespace boxm2_add_block_process_globals;

  if ( pro.n_inputs() < n_inputs_ ) {
    vcl_cout << pro.name() << ": The input number should be " << n_inputs_<< vcl_endl;
    return false;
  }
  //get the inputs
  unsigned i = 0;
  boxm2_scene_sptr scene    =pro.get_input<boxm2_scene_sptr>(i++);
  int index_i          =pro.get_input<int>        (i++);
  int index_j          =pro.get_input<int>        (i++);
  int index_k          =pro.get_input<int>        (i++);
  unsigned num_x            =pro.get_input<unsigned>        (i++);
  unsigned num_y            =pro.get_input<unsigned>        (i++);
  unsigned num_z            =pro.get_input<unsigned>        (i++);

  unsigned max_num_lvls     =pro.get_input<unsigned>        (i++);

  float    local_x          =pro.get_input<float>           (i++);
  float    local_y          =pro.get_input<float>           (i++);
  float    local_z          =pro.get_input<float>           (i++);

  float    blk_dims         =pro.get_input<float>           (i++);
  float    max_data_size    =pro.get_input<float>           (i++);
  float    p_init           =pro.get_input<float>           (i++);

  unsigned init_level     =pro.get_input<unsigned>        (i++);

  boxm2_block_id id(index_i,index_j,index_k);
  vcl_map<boxm2_block_id, boxm2_block_metadata> blks=scene->blocks();

  if (blks.find(id)!=blks.end())
  {
      vcl_cout<<"block already exists"<<vcl_endl;
      return false;
  }

  boxm2_block_metadata mdata(id,
                             vgl_point_3d<double>(local_x,local_y,local_z),
                             vgl_vector_3d<double>(blk_dims,blk_dims,blk_dims),
                             vgl_vector_3d<unsigned>(num_x,num_y,num_z),
                             init_level,max_num_lvls,max_data_size,p_init);

  blks[id]=mdata;
  scene->set_blocks(blks);

  return true;
}
