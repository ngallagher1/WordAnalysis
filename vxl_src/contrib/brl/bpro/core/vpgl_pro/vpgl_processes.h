#ifndef vpgl_processes_h_
#define vpgl_processes_h_

#include <bprb/bprb_macros.h>
#include <bprb/bprb_func_process.h>

// execute and const functions
DECLARE_FUNC_CONS(vpgl_load_proj_camera_process);
DECLARE_FUNC_CONS(vpgl_load_local_rational_camera_process);
DECLARE_FUNC_CONS(vpgl_load_rational_camera_process);
DECLARE_FUNC_CONS(vpgl_load_rational_camera_nitf_process);
DECLARE_FUNC_CONS(vpgl_load_perspective_camera_process);
DECLARE_FUNC_CONS(vpgl_save_rational_camera_process);
DECLARE_FUNC_CONS(vpgl_save_perspective_camera_process);
DECLARE_FUNC_CONS(vpgl_nitf_camera_coverage_process);
DECLARE_FUNC_CONS(vpgl_create_local_rational_camera_process);
DECLARE_FUNC_CONS(vpgl_create_local_rational_camera_nitf_process);
DECLARE_FUNC_CONS(vpgl_projective_to_rational_camera_process);
DECLARE_FUNC_CONS(vpgl_correct_rational_camera_process);
DECLARE_FUNC_CONS(vpgl_create_perspective_camera_process);
DECLARE_FUNC_CONS(vpgl_save_perspective_camera_vrml_process);
DECLARE_FUNC_CONS(vpgl_save_perspective_cameras_vrml_process);
DECLARE_FUNC_CONS(vpgl_correct_rational_cameras_process);
DECLARE_FUNC_CONS(vpgl_correct_rational_cameras_mult_corr_process);
DECLARE_FUNC_CONS(vpgl_correct_rational_cameras_mult_corr_refine_process);
DECLARE_FUNC_CONS(vpgl_project_process);
DECLARE_FUNC_CONS(vpgl_convert_to_generic_camera_process);
DECLARE_FUNC_CONS(vpgl_convert_local_rational_to_generic_process);
DECLARE_FUNC_CONS(vpgl_resample_perspective_camera_process);
DECLARE_FUNC_CONS(vpgl_generate_3d_point_from_depth_process);
DECLARE_FUNC_CONS(vpgl_get_view_direction_at_point_process);
DECLARE_FUNC_CONS(vpgl_get_rpc_offsets_process);
DECLARE_FUNC_CONS(vpgl_get_bounding_box_process);
DECLARE_FUNC_CONS(vpgl_nitf_footprint_process);
DECLARE_FUNC_CONS(vpgl_generate_3d_point_from_cams_process);
DECLARE_FUNC_CONS(vpgl_convert_to_local_coordinates_process);

DECLARE_FUNC_CONS(vpgl_perturb_persp_cam_orient_process);
DECLARE_FUNC_CONS(vpgl_rotate_persp_cam_process);
DECLARE_FUNC_CONS(vpgl_persp_cam_distance_process);
DECLARE_FUNC_CONS(vpgl_convert_to_generic_camera_w_margin_process);
DECLARE_FUNC_CONS(vpgl_compute_persp_cam_pa_covariance_process);
DECLARE_FUNC_CONS(vpgl_create_perspective_camera_process2);
DECLARE_FUNC_CONS(vpgl_get_perspective_cam_center_process);
DECLARE_FUNC_CONS(vpgl_load_geo_camera_process);
DECLARE_FUNC_CONS(vpgl_create_perspective_camera_process3);
DECLARE_FUNC_CONS(vpgl_create_perspective_camera_process4);
DECLARE_FUNC_CONS(vpgl_perturb_uniform_persp_cam_orient_process);
DECLARE_FUNC_CONS(vpgl_load_affine_camera_process);
DECLARE_FUNC_CONS(bpgl_transform_perspective_cameras_process);
DECLARE_FUNC_CONS(vpgl_geo_footprint_process);
DECLARE_FUNC_CONS(vpgl_translate_geo_camera_process);
DECLARE_FUNC_CONS(vpgl_convert_geo_camera_to_generic_process);
DECLARE_FUNC_CONS(vpgl_create_perspective_camera_from_kml_process);
DECLARE_FUNC_CONS(vpgl_convert_to_local_coordinates_process2);
DECLARE_FUNC_CONS(vpgl_load_perspective_camera_from_kml_file_process);
DECLARE_FUNC_CONS(vpgl_geo_cam_global_to_img_process);
DECLARE_FUNC_CONS(vpgl_load_geo_camera_process2);
DECLARE_FUNC_CONS(vpgl_export_cameras_to_nvm_process);
DECLARE_FUNC_CONS(vpgl_create_lvcs_process);
DECLARE_FUNC_CONS(vpgl_convert_local_to_global_coordinates_process);
DECLARE_FUNC_CONS(vpgl_convert_local_rational_to_perspective_process);
DECLARE_FUNC_CONS(vpgl_load_geo_camera_process3);
DECLARE_FUNC_CONS(vpgl_save_geo_camera_tfw_process);
DECLARE_FUNC_CONS(vpgl_interpolate_perspective_cameras_process);
DECLARE_FUNC_CONS(vpgl_load_lvcs_process);
DECLARE_FUNC_CONS(vpgl_get_rational_camera_offsets_process);
DECLARE_FUNC_CONS(vpgl_write_generic_camera_process);
DECLARE_FUNC_CONS(vpgl_compute_affine_from_rat_process);
DECLARE_FUNC_CONS(vpgl_affine_rectify_images_process);
DECLARE_FUNC_CONS(vpgl_save_projective_camera_process);

#endif