#ifndef IIT_ROBOGEN__M2L_TRAITS_H_
#define IIT_ROBOGEN__M2L_TRAITS_H_

#include "declarations.h"
#include "transforms.h"
#include "inverse_dynamics.h"
#include "forward_dynamics.h"
#include "jsim.h"
#include "inertia_properties.h"

namespace iit {
namespace M2L {

struct Traits {
    typedef typename M2L::ScalarTraits ScalarTraits;

    typedef typename M2L::JointState JointState;

    typedef typename M2L::JointIdentifiers JointID;
    typedef typename M2L::LinkIdentifiers  LinkID;

    typedef typename M2L::HomogeneousTransforms HomogeneousTransforms;
    typedef typename M2L::MotionTransforms MotionTransforms;
    typedef typename M2L::ForceTransforms ForceTransforms;

    typedef typename M2L::dyn::InertiaProperties InertiaProperties;
    typedef typename M2L::dyn::ForwardDynamics FwdDynEngine;
    typedef typename M2L::dyn::InverseDynamics InvDynEngine;
    typedef typename M2L::dyn::JSIM JSIM;

    static const int joints_count = M2L::jointsCount;
    static const int links_count  = M2L::linksCount;
    static const bool floating_base = false;

    static inline const JointID* orderedJointIDs();
    static inline const LinkID*  orderedLinkIDs();
};


inline const Traits::JointID*  Traits::orderedJointIDs() {
    return M2L::orderedJointIDs;
}
inline const Traits::LinkID*  Traits::orderedLinkIDs() {
    return M2L::orderedLinkIDs;
}

}
}

#endif
