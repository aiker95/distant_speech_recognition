/**
 * @file square_root.h
 * @brief Updating complex Cholesky factorizations.
 * @author John McDonough and Kenichi Kumatani
 */

#ifndef SQUARE_ROOT_H
#define SQUARE_ROOT_H

#include <stdio.h>
#include <assert.h>

#include <gsl/gsl_block.h>
#include <gsl/gsl_vector.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_complex.h>
#include <gsl/gsl_complex_math.h>
#include "common/jexception.h"

void cholesky_backsub(const gsl_matrix* A, gsl_vector* x);

void vector_matrix_product(const gsl_vector_complex* vec,
			 const gsl_matrix_complex* mat, gsl_matrix* D);

void make_conjugate_symmetric(gsl_matrix_complex* mat);

void cholesky_forwardsub(const gsl_matrix* A, gsl_vector* x);

void cholesky_forwardsub_complex(const gsl_matrix_complex* lt,
			       const gsl_vector_complex* rhs,
			       gsl_vector_complex* lhs,
			       bool conjugate = false);

void cholesky_backsub_complex(const gsl_matrix_complex* lt,
                              const gsl_vector_complex* rhs,
                              gsl_vector_complex* lhs,
                              bool conjugate = false);

void rank_one_update_cholesky_factor(gsl_matrix_complex* A11,
                                     const double alpha_m,
                                     const gsl_vector_complex* c_m);

void propagate_covar_square_root_real(gsl_matrix* A11,
                                      gsl_matrix* A12,
                                      gsl_matrix* A21,
                                      gsl_matrix* A22, bool flag = false);

void sweep_lower_triangular(gsl_matrix* A, gsl_matrix* B);

void propagate_covar_square_root_step1(gsl_matrix_complex* A12,
                                       gsl_matrix_complex* A22);

void propagate_covar_square_root_step2a(gsl_matrix_complex* A11,
                                        gsl_matrix_complex* A12,
                                        gsl_matrix_complex* A21,
                                        gsl_matrix_complex* A22);

void propagate_covar_square_root_step2b(gsl_matrix_complex* A22);

void propagate_covar_square_root(gsl_matrix_complex* A11,
                                 gsl_matrix_complex* A12,
                                 gsl_matrix_complex* A21,
                                 gsl_matrix_complex* A22);

void propagate_info_square_root(gsl_matrix_complex* sqrt_Pm_inv,
                                gsl_matrix_complex* A12,
                                gsl_vector_complex* a_21,
                                gsl_vector_complex* a_22, bool rankOneA12 = true);

void propagate_info_square_root_step2_rls(gsl_matrix_complex* sqrt_Pm_inv,
                                          gsl_vector_complex* a_12,
                                          gsl_vector_complex* a_21,
                                          gsl_complex a_22);

void propagate_info_square_root_rls(gsl_matrix_complex* sqrt_Pm_inv,
                                    gsl_vector_complex* a_12,
                                    gsl_vector_complex* a_21,
                                    gsl_complex a_22);

void add_diagonal_loading(gsl_matrix_complex* sqrt_Pm_inv, int dim, double wght);

gsl_vector* cholesky_diagonal(gsl_vector* v, const gsl_matrix* m);
gsl_vector* square_diagonal(gsl_vector* v, const gsl_matrix* m);

#endif
