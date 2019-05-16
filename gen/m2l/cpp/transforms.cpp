#include "transforms.h"

using namespace iit::M2L;

// Constructors

MotionTransforms::MotionTransforms()
 :     fr_link1_X_fr_base0(),
    fr_base0_X_fr_link1(),
    fr_link2_X_fr_link1(),
    fr_link1_X_fr_link2()
{}
void MotionTransforms::updateParams(const Params_lengths& v_lengths, const Params_angles& v_angles)
{
    params.lengths = v_lengths;
    params.angles = v_angles;
    params.trig.update();
}

ForceTransforms::ForceTransforms()
 :     fr_link1_X_fr_base0(),
    fr_base0_X_fr_link1(),
    fr_link2_X_fr_link1(),
    fr_link1_X_fr_link2()
{}
void ForceTransforms::updateParams(const Params_lengths& v_lengths, const Params_angles& v_angles)
{
    params.lengths = v_lengths;
    params.angles = v_angles;
    params.trig.update();
}

HomogeneousTransforms::HomogeneousTransforms()
 :     fr_link1_X_fr_base0(),
    fr_base0_X_fr_link1(),
    fr_link2_X_fr_link1(),
    fr_link1_X_fr_link2()
{}
void HomogeneousTransforms::updateParams(const Params_lengths& v_lengths, const Params_angles& v_angles)
{
    params.lengths = v_lengths;
    params.angles = v_angles;
    params.trig.update();
}

MotionTransforms::Type_fr_link1_X_fr_base0::Type_fr_link1_X_fr_base0()
{
    (*this)(0,2) = 0.0;
    (*this)(0,3) = 0.0;
    (*this)(0,4) = 0.0;
    (*this)(0,5) = 0.0;
    (*this)(1,2) = 0.0;
    (*this)(1,3) = 0.0;
    (*this)(1,4) = 0.0;
    (*this)(1,5) = 0.0;
    (*this)(2,0) = 0.0;
    (*this)(2,1) = 0.0;
    (*this)(2,2) = 1.0;
    (*this)(2,3) = 0.0;
    (*this)(2,4) = 0.0;
    (*this)(2,5) = 0.0;
    (*this)(3,0) = 0.0;
    (*this)(3,1) = 0.0;
    (*this)(3,2) = 0.0;
    (*this)(3,5) = 0.0;
    (*this)(4,0) = 0.0;
    (*this)(4,1) = 0.0;
    (*this)(4,2) = 0.0;
    (*this)(4,5) = 0.0;
    (*this)(5,0) = 0.0;
    (*this)(5,1) = 0.0;
    (*this)(5,2) = 0.0;
    (*this)(5,3) = 0.0;
    (*this)(5,4) = 0.0;
    (*this)(5,5) = 1.0;
}

const MotionTransforms::Type_fr_link1_X_fr_base0& MotionTransforms::Type_fr_link1_X_fr_base0::update(const state_t& q)
{
    Scalar sin_q_jA  = ScalarTraits::sin( q(JA) );
    Scalar cos_q_jA  = ScalarTraits::cos( q(JA) );
    (*this)(0,0) = cos_q_jA;
    (*this)(0,1) = sin_q_jA;
    (*this)(1,0) = -sin_q_jA;
    (*this)(1,1) = cos_q_jA;
    (*this)(3,3) = cos_q_jA;
    (*this)(3,4) = sin_q_jA;
    (*this)(4,3) = -sin_q_jA;
    (*this)(4,4) = cos_q_jA;
    return *this;
}
MotionTransforms::Type_fr_base0_X_fr_link1::Type_fr_base0_X_fr_link1()
{
    (*this)(0,2) = 0.0;
    (*this)(0,3) = 0.0;
    (*this)(0,4) = 0.0;
    (*this)(0,5) = 0.0;
    (*this)(1,2) = 0.0;
    (*this)(1,3) = 0.0;
    (*this)(1,4) = 0.0;
    (*this)(1,5) = 0.0;
    (*this)(2,0) = 0.0;
    (*this)(2,1) = 0.0;
    (*this)(2,2) = 1.0;
    (*this)(2,3) = 0.0;
    (*this)(2,4) = 0.0;
    (*this)(2,5) = 0.0;
    (*this)(3,0) = 0.0;
    (*this)(3,1) = 0.0;
    (*this)(3,2) = 0.0;
    (*this)(3,5) = 0.0;
    (*this)(4,0) = 0.0;
    (*this)(4,1) = 0.0;
    (*this)(4,2) = 0.0;
    (*this)(4,5) = 0.0;
    (*this)(5,0) = 0.0;
    (*this)(5,1) = 0.0;
    (*this)(5,2) = 0.0;
    (*this)(5,3) = 0.0;
    (*this)(5,4) = 0.0;
    (*this)(5,5) = 1.0;
}

const MotionTransforms::Type_fr_base0_X_fr_link1& MotionTransforms::Type_fr_base0_X_fr_link1::update(const state_t& q)
{
    Scalar sin_q_jA  = ScalarTraits::sin( q(JA) );
    Scalar cos_q_jA  = ScalarTraits::cos( q(JA) );
    (*this)(0,0) = cos_q_jA;
    (*this)(0,1) = -sin_q_jA;
    (*this)(1,0) = sin_q_jA;
    (*this)(1,1) = cos_q_jA;
    (*this)(3,3) = cos_q_jA;
    (*this)(3,4) = -sin_q_jA;
    (*this)(4,3) = sin_q_jA;
    (*this)(4,4) = cos_q_jA;
    return *this;
}
MotionTransforms::Type_fr_link2_X_fr_link1::Type_fr_link2_X_fr_link1()
{
    (*this)(0,2) = 0.0;
    (*this)(0,3) = 0.0;
    (*this)(0,4) = 0.0;
    (*this)(0,5) = 0.0;
    (*this)(1,2) = 0.0;
    (*this)(1,3) = 0.0;
    (*this)(1,4) = 0.0;
    (*this)(1,5) = 0.0;
    (*this)(2,0) = 0.0;
    (*this)(2,1) = 0.0;
    (*this)(2,2) = 1.0;
    (*this)(2,3) = 0.0;
    (*this)(2,4) = 0.0;
    (*this)(2,5) = 0.0;
    (*this)(3,0) = 0.0;
    (*this)(3,1) = 0.0;
    (*this)(3,5) = 0.0;
    (*this)(4,0) = 0.0;
    (*this)(4,1) = 0.0;
    (*this)(4,5) = 0.0;
    (*this)(5,0) = 0.0;
    (*this)(5,1) = - tx_jB;    // Maxima DSL: -_k__tx_jB
    (*this)(5,2) = 0.0;
    (*this)(5,3) = 0.0;
    (*this)(5,4) = 0.0;
    (*this)(5,5) = 1.0;
}

const MotionTransforms::Type_fr_link2_X_fr_link1& MotionTransforms::Type_fr_link2_X_fr_link1::update(const state_t& q)
{
    Scalar sin_q_jB  = ScalarTraits::sin( q(JB) );
    Scalar cos_q_jB  = ScalarTraits::cos( q(JB) );
    (*this)(0,0) = cos_q_jB;
    (*this)(0,1) = sin_q_jB;
    (*this)(1,0) = -sin_q_jB;
    (*this)(1,1) = cos_q_jB;
    (*this)(3,2) =  tx_jB * sin_q_jB;
    (*this)(3,3) = cos_q_jB;
    (*this)(3,4) = sin_q_jB;
    (*this)(4,2) =  tx_jB * cos_q_jB;
    (*this)(4,3) = -sin_q_jB;
    (*this)(4,4) = cos_q_jB;
    return *this;
}
MotionTransforms::Type_fr_link1_X_fr_link2::Type_fr_link1_X_fr_link2()
{
    (*this)(0,2) = 0.0;
    (*this)(0,3) = 0.0;
    (*this)(0,4) = 0.0;
    (*this)(0,5) = 0.0;
    (*this)(1,2) = 0.0;
    (*this)(1,3) = 0.0;
    (*this)(1,4) = 0.0;
    (*this)(1,5) = 0.0;
    (*this)(2,0) = 0.0;
    (*this)(2,1) = 0.0;
    (*this)(2,2) = 1.0;
    (*this)(2,3) = 0.0;
    (*this)(2,4) = 0.0;
    (*this)(2,5) = 0.0;
    (*this)(3,0) = 0.0;
    (*this)(3,1) = 0.0;
    (*this)(3,2) = 0.0;
    (*this)(3,5) = 0.0;
    (*this)(4,0) = 0.0;
    (*this)(4,1) = 0.0;
    (*this)(4,2) = - tx_jB;    // Maxima DSL: -_k__tx_jB
    (*this)(4,5) = 0.0;
    (*this)(5,2) = 0.0;
    (*this)(5,3) = 0.0;
    (*this)(5,4) = 0.0;
    (*this)(5,5) = 1.0;
}

const MotionTransforms::Type_fr_link1_X_fr_link2& MotionTransforms::Type_fr_link1_X_fr_link2::update(const state_t& q)
{
    Scalar sin_q_jB  = ScalarTraits::sin( q(JB) );
    Scalar cos_q_jB  = ScalarTraits::cos( q(JB) );
    (*this)(0,0) = cos_q_jB;
    (*this)(0,1) = -sin_q_jB;
    (*this)(1,0) = sin_q_jB;
    (*this)(1,1) = cos_q_jB;
    (*this)(3,3) = cos_q_jB;
    (*this)(3,4) = -sin_q_jB;
    (*this)(4,3) = sin_q_jB;
    (*this)(4,4) = cos_q_jB;
    (*this)(5,0) =  tx_jB * sin_q_jB;
    (*this)(5,1) =  tx_jB * cos_q_jB;
    return *this;
}

ForceTransforms::Type_fr_link1_X_fr_base0::Type_fr_link1_X_fr_base0()
{
    (*this)(0,2) = 0.0;
    (*this)(0,3) = 0.0;
    (*this)(0,4) = 0.0;
    (*this)(0,5) = 0.0;
    (*this)(1,2) = 0.0;
    (*this)(1,3) = 0.0;
    (*this)(1,4) = 0.0;
    (*this)(1,5) = 0.0;
    (*this)(2,0) = 0.0;
    (*this)(2,1) = 0.0;
    (*this)(2,2) = 1.0;
    (*this)(2,3) = 0.0;
    (*this)(2,4) = 0.0;
    (*this)(2,5) = 0.0;
    (*this)(3,0) = 0.0;
    (*this)(3,1) = 0.0;
    (*this)(3,2) = 0.0;
    (*this)(3,5) = 0.0;
    (*this)(4,0) = 0.0;
    (*this)(4,1) = 0.0;
    (*this)(4,2) = 0.0;
    (*this)(4,5) = 0.0;
    (*this)(5,0) = 0.0;
    (*this)(5,1) = 0.0;
    (*this)(5,2) = 0.0;
    (*this)(5,3) = 0.0;
    (*this)(5,4) = 0.0;
    (*this)(5,5) = 1.0;
}

const ForceTransforms::Type_fr_link1_X_fr_base0& ForceTransforms::Type_fr_link1_X_fr_base0::update(const state_t& q)
{
    Scalar sin_q_jA  = ScalarTraits::sin( q(JA) );
    Scalar cos_q_jA  = ScalarTraits::cos( q(JA) );
    (*this)(0,0) = cos_q_jA;
    (*this)(0,1) = sin_q_jA;
    (*this)(1,0) = -sin_q_jA;
    (*this)(1,1) = cos_q_jA;
    (*this)(3,3) = cos_q_jA;
    (*this)(3,4) = sin_q_jA;
    (*this)(4,3) = -sin_q_jA;
    (*this)(4,4) = cos_q_jA;
    return *this;
}
ForceTransforms::Type_fr_base0_X_fr_link1::Type_fr_base0_X_fr_link1()
{
    (*this)(0,2) = 0.0;
    (*this)(0,3) = 0.0;
    (*this)(0,4) = 0.0;
    (*this)(0,5) = 0.0;
    (*this)(1,2) = 0.0;
    (*this)(1,3) = 0.0;
    (*this)(1,4) = 0.0;
    (*this)(1,5) = 0.0;
    (*this)(2,0) = 0.0;
    (*this)(2,1) = 0.0;
    (*this)(2,2) = 1.0;
    (*this)(2,3) = 0.0;
    (*this)(2,4) = 0.0;
    (*this)(2,5) = 0.0;
    (*this)(3,0) = 0.0;
    (*this)(3,1) = 0.0;
    (*this)(3,2) = 0.0;
    (*this)(3,5) = 0.0;
    (*this)(4,0) = 0.0;
    (*this)(4,1) = 0.0;
    (*this)(4,2) = 0.0;
    (*this)(4,5) = 0.0;
    (*this)(5,0) = 0.0;
    (*this)(5,1) = 0.0;
    (*this)(5,2) = 0.0;
    (*this)(5,3) = 0.0;
    (*this)(5,4) = 0.0;
    (*this)(5,5) = 1.0;
}

const ForceTransforms::Type_fr_base0_X_fr_link1& ForceTransforms::Type_fr_base0_X_fr_link1::update(const state_t& q)
{
    Scalar sin_q_jA  = ScalarTraits::sin( q(JA) );
    Scalar cos_q_jA  = ScalarTraits::cos( q(JA) );
    (*this)(0,0) = cos_q_jA;
    (*this)(0,1) = -sin_q_jA;
    (*this)(1,0) = sin_q_jA;
    (*this)(1,1) = cos_q_jA;
    (*this)(3,3) = cos_q_jA;
    (*this)(3,4) = -sin_q_jA;
    (*this)(4,3) = sin_q_jA;
    (*this)(4,4) = cos_q_jA;
    return *this;
}
ForceTransforms::Type_fr_link2_X_fr_link1::Type_fr_link2_X_fr_link1()
{
    (*this)(0,2) = 0.0;
    (*this)(0,3) = 0.0;
    (*this)(0,4) = 0.0;
    (*this)(1,2) = 0.0;
    (*this)(1,3) = 0.0;
    (*this)(1,4) = 0.0;
    (*this)(2,0) = 0.0;
    (*this)(2,1) = 0.0;
    (*this)(2,2) = 1.0;
    (*this)(2,3) = 0.0;
    (*this)(2,4) = - tx_jB;    // Maxima DSL: -_k__tx_jB
    (*this)(2,5) = 0.0;
    (*this)(3,0) = 0.0;
    (*this)(3,1) = 0.0;
    (*this)(3,2) = 0.0;
    (*this)(3,5) = 0.0;
    (*this)(4,0) = 0.0;
    (*this)(4,1) = 0.0;
    (*this)(4,2) = 0.0;
    (*this)(4,5) = 0.0;
    (*this)(5,0) = 0.0;
    (*this)(5,1) = 0.0;
    (*this)(5,2) = 0.0;
    (*this)(5,3) = 0.0;
    (*this)(5,4) = 0.0;
    (*this)(5,5) = 1.0;
}

const ForceTransforms::Type_fr_link2_X_fr_link1& ForceTransforms::Type_fr_link2_X_fr_link1::update(const state_t& q)
{
    Scalar sin_q_jB  = ScalarTraits::sin( q(JB) );
    Scalar cos_q_jB  = ScalarTraits::cos( q(JB) );
    (*this)(0,0) = cos_q_jB;
    (*this)(0,1) = sin_q_jB;
    (*this)(0,5) =  tx_jB * sin_q_jB;
    (*this)(1,0) = -sin_q_jB;
    (*this)(1,1) = cos_q_jB;
    (*this)(1,5) =  tx_jB * cos_q_jB;
    (*this)(3,3) = cos_q_jB;
    (*this)(3,4) = sin_q_jB;
    (*this)(4,3) = -sin_q_jB;
    (*this)(4,4) = cos_q_jB;
    return *this;
}
ForceTransforms::Type_fr_link1_X_fr_link2::Type_fr_link1_X_fr_link2()
{
    (*this)(0,2) = 0.0;
    (*this)(0,3) = 0.0;
    (*this)(0,4) = 0.0;
    (*this)(0,5) = 0.0;
    (*this)(1,2) = 0.0;
    (*this)(1,3) = 0.0;
    (*this)(1,4) = 0.0;
    (*this)(1,5) = - tx_jB;    // Maxima DSL: -_k__tx_jB
    (*this)(2,0) = 0.0;
    (*this)(2,1) = 0.0;
    (*this)(2,2) = 1.0;
    (*this)(2,5) = 0.0;
    (*this)(3,0) = 0.0;
    (*this)(3,1) = 0.0;
    (*this)(3,2) = 0.0;
    (*this)(3,5) = 0.0;
    (*this)(4,0) = 0.0;
    (*this)(4,1) = 0.0;
    (*this)(4,2) = 0.0;
    (*this)(4,5) = 0.0;
    (*this)(5,0) = 0.0;
    (*this)(5,1) = 0.0;
    (*this)(5,2) = 0.0;
    (*this)(5,3) = 0.0;
    (*this)(5,4) = 0.0;
    (*this)(5,5) = 1.0;
}

const ForceTransforms::Type_fr_link1_X_fr_link2& ForceTransforms::Type_fr_link1_X_fr_link2::update(const state_t& q)
{
    Scalar sin_q_jB  = ScalarTraits::sin( q(JB) );
    Scalar cos_q_jB  = ScalarTraits::cos( q(JB) );
    (*this)(0,0) = cos_q_jB;
    (*this)(0,1) = -sin_q_jB;
    (*this)(1,0) = sin_q_jB;
    (*this)(1,1) = cos_q_jB;
    (*this)(2,3) =  tx_jB * sin_q_jB;
    (*this)(2,4) =  tx_jB * cos_q_jB;
    (*this)(3,3) = cos_q_jB;
    (*this)(3,4) = -sin_q_jB;
    (*this)(4,3) = sin_q_jB;
    (*this)(4,4) = cos_q_jB;
    return *this;
}

HomogeneousTransforms::Type_fr_link1_X_fr_base0::Type_fr_link1_X_fr_base0()
{
    (*this)(0,2) = 0.0;
    (*this)(0,3) = 0.0;
    (*this)(1,2) = 0.0;
    (*this)(1,3) = 0.0;
    (*this)(2,0) = 0.0;
    (*this)(2,1) = 0.0;
    (*this)(2,2) = 1.0;
    (*this)(2,3) = 0.0;
    (*this)(3,0) = 0.0;
    (*this)(3,1) = 0.0;
    (*this)(3,2) = 0.0;
    (*this)(3,3) = 1.0;
}

const HomogeneousTransforms::Type_fr_link1_X_fr_base0& HomogeneousTransforms::Type_fr_link1_X_fr_base0::update(const state_t& q)
{
    Scalar sin_q_jA  = ScalarTraits::sin( q(JA) );
    Scalar cos_q_jA  = ScalarTraits::cos( q(JA) );
    (*this)(0,0) = cos_q_jA;
    (*this)(0,1) = sin_q_jA;
    (*this)(1,0) = -sin_q_jA;
    (*this)(1,1) = cos_q_jA;
    return *this;
}
HomogeneousTransforms::Type_fr_base0_X_fr_link1::Type_fr_base0_X_fr_link1()
{
    (*this)(0,2) = 0.0;
    (*this)(0,3) = 0.0;
    (*this)(1,2) = 0.0;
    (*this)(1,3) = 0.0;
    (*this)(2,0) = 0.0;
    (*this)(2,1) = 0.0;
    (*this)(2,2) = 1.0;
    (*this)(2,3) = 0.0;
    (*this)(3,0) = 0.0;
    (*this)(3,1) = 0.0;
    (*this)(3,2) = 0.0;
    (*this)(3,3) = 1.0;
}

const HomogeneousTransforms::Type_fr_base0_X_fr_link1& HomogeneousTransforms::Type_fr_base0_X_fr_link1::update(const state_t& q)
{
    Scalar sin_q_jA  = ScalarTraits::sin( q(JA) );
    Scalar cos_q_jA  = ScalarTraits::cos( q(JA) );
    (*this)(0,0) = cos_q_jA;
    (*this)(0,1) = -sin_q_jA;
    (*this)(1,0) = sin_q_jA;
    (*this)(1,1) = cos_q_jA;
    return *this;
}
HomogeneousTransforms::Type_fr_link2_X_fr_link1::Type_fr_link2_X_fr_link1()
{
    (*this)(0,2) = 0.0;
    (*this)(1,2) = 0.0;
    (*this)(2,0) = 0.0;
    (*this)(2,1) = 0.0;
    (*this)(2,2) = 1.0;
    (*this)(2,3) = 0.0;
    (*this)(3,0) = 0.0;
    (*this)(3,1) = 0.0;
    (*this)(3,2) = 0.0;
    (*this)(3,3) = 1.0;
}

const HomogeneousTransforms::Type_fr_link2_X_fr_link1& HomogeneousTransforms::Type_fr_link2_X_fr_link1::update(const state_t& q)
{
    Scalar sin_q_jB  = ScalarTraits::sin( q(JB) );
    Scalar cos_q_jB  = ScalarTraits::cos( q(JB) );
    (*this)(0,0) = cos_q_jB;
    (*this)(0,1) = sin_q_jB;
    (*this)(0,3) = - tx_jB * cos_q_jB;
    (*this)(1,0) = -sin_q_jB;
    (*this)(1,1) = cos_q_jB;
    (*this)(1,3) =  tx_jB * sin_q_jB;
    return *this;
}
HomogeneousTransforms::Type_fr_link1_X_fr_link2::Type_fr_link1_X_fr_link2()
{
    (*this)(0,2) = 0.0;
    (*this)(0,3) =  tx_jB;    // Maxima DSL: _k__tx_jB
    (*this)(1,2) = 0.0;
    (*this)(1,3) = 0.0;
    (*this)(2,0) = 0.0;
    (*this)(2,1) = 0.0;
    (*this)(2,2) = 1.0;
    (*this)(2,3) = 0.0;
    (*this)(3,0) = 0.0;
    (*this)(3,1) = 0.0;
    (*this)(3,2) = 0.0;
    (*this)(3,3) = 1.0;
}

const HomogeneousTransforms::Type_fr_link1_X_fr_link2& HomogeneousTransforms::Type_fr_link1_X_fr_link2::update(const state_t& q)
{
    Scalar sin_q_jB  = ScalarTraits::sin( q(JB) );
    Scalar cos_q_jB  = ScalarTraits::cos( q(JB) );
    (*this)(0,0) = cos_q_jB;
    (*this)(0,1) = -sin_q_jB;
    (*this)(1,0) = sin_q_jB;
    (*this)(1,1) = cos_q_jB;
    return *this;
}

