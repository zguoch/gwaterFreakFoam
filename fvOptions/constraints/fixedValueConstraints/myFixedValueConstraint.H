/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) 2016-2018 OpenFOAM Foundation
     \\/     M anipulation  |
-------------------------------------------------------------------------------
License
    This file is part of OpenFOAM.

    OpenFOAM is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM.  If not, see <http://www.gnu.org/licenses/>.

Class
    Foam::fv::myFixedValueConstraint

Description
    Constrain the field values within a specified region.

Usage
    For example to set the turbulence properties within a porous region:
    \verbatim
    porosityTurbulence
    {
        type            scalarmyFixedValueConstraint;
        active          yes;

        selectionMode   cellZone;
        cellZone        porosity;
        fieldValues
        {
            k           1;
            epsilon     150;
        }
    }
    \endverbatim

See also
    Foam::fvOption

SourceFiles
    myFixedValueConstraint.C
    myfixedValueConstraints.C

\*---------------------------------------------------------------------------*/

#ifndef myFixedValueConstraint_H
#define myFixedValueConstraint_H

#include "cellSetOption.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{
namespace fv
{

/*---------------------------------------------------------------------------*\
                       Class myFixedValueConstraint Declaration
\*---------------------------------------------------------------------------*/

template<class Type>
class myFixedValueConstraint
:
    public cellSetOption
{
    // Private member data

        //- Field values
        List<Type> fieldValues_;


public:

    //- Runtime type information
    TypeName("myFixedValueConstraint");


    // Constructors

        //- Construct from components
        myFixedValueConstraint
        (
            const word& name,
            const word& modelType,
            const dictionary& dict,
            const fvMesh& mesh
        );


    // Member Functions

        //- Read source dictionary
        virtual bool read(const dictionary& dict);

        //- Set value on field
        //virtual void constrain(fvMatrix<Type>& eqn, const label fieldi);

        //- Set value on field
        virtual void constrain( fvMatrix<Type>& eqn, const label fieldi); //const volScalarField& v0,
		
        //virtual void constrain( const volScalarField& kr, fvMatrix<Type>& eqn, const label fieldi );

};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace fv
} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#ifdef NoRepository
    #include "myFixedValueConstraint.C"
#endif

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
