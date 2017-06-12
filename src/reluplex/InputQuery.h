/*********************                                                        */
/*! \file InputQuery.h
 ** \verbatim
 ** Top contributors (to current version):
 **   Guy Katz
 ** This file is part of the Reluplex project.
 ** Copyright (c) 2016-2017 by the authors listed in the file AUTHORS
 ** in the top-level source directory) and their institutional affiliations.
 ** All rights reserved. See the file COPYING in the top-level source
 ** directory for licensing information.\endverbatim
 **/

#ifndef __InputQuery_h__
#define __InputQuery_h__

#include "List.h"
#include "Map.h"

class InputQuery
{
public:
    /* A class representing a single input equation. For now, all
    equations are interpreted as equalities, i.e. the sum of all
    addends plus scalar needs to be equal to 0. */
    struct Equation
    {
    public:
        struct Addend
        {
        public:
            Addend( double coefficient, unsigned variable );

            double _coefficient;
            unsigned _variable;
        };

        void addAddend( double coefficient, unsigned variable );
        void setScalar( double scalar );

        List<Addend> _addends;
        double _scalar;
    };

    InputQuery();
    ~InputQuery();

    void setNumberOfVariables( unsigned numberOfVariables );
    void setLowerBound( unsigned variable, double bound );
    void setUpperBound( unsigned variable, double bound );

    void addEquation( const Equation &equation );

    double getNumberOfVariables() const;
    double getLowerBound( unsigned variable ) const;
    double getUpperBound( unsigned variable ) const;

private:
    unsigned _numberOfVariables;
    List<InputQuery::Equation> _equations;
    Map<unsigned, double> _lowerBounds;
    Map<unsigned, double> _upperBounds;
};

#endif // __InputQuery_h__

//
// Local Variables:
// compile-command: "make -C .. "
// tags-file-name: "../TAGS"
// c-basic-offset: 4
// End:
//
