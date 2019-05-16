#ifndef M2L_JACOBIANS_H_
#define M2L_JACOBIANS_H_

#include <iit/rbd/TransformsBase.h>
#include "declarations.h"
#include "kinematics_parameters.h"
#include "model_constants.h"

namespace iit {
namespace M2L {

template<int COLS, class M>
class JacobianT : public iit::rbd::JacobianBase<JointState, COLS, M>
{};

/**
 *
 */
class Jacobians
{
    public:
    public:
        Jacobians();
        void updateParameters(const Params_lengths& _lengths, const Params_angles& _angles);
    public:

    protected:
        Params_lengths lengths;
        Params_angles angles;
};


}
}

#endif
