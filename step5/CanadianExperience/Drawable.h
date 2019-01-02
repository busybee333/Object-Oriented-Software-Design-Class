/**
 * \file Drawable.h
 *
 * \author Romi Yun
 *
 * Abstract base class for drawable elements of our picture
 */

#pragma once

#include <memory>
#include <string>
#include <vector>

using namespace std;

class CActor;

/**
 * Abstract base class for drawable elements of our picture
 */
class CDrawable
{
public:
	/// Destructor
	virtual ~CDrawable();

	/** Default constructor disabled */
	CDrawable() = delete;

	/** Copy constructor disabled */
	CDrawable(const CDrawable &) = delete;

	/** Assignment operator disabled */
	void operator=(const CDrawable &) = delete;

	/**
	 * Set the actor using this drawable
	 * \param actor Actor using this drawable
	 */
	void SetActor(CActor *actor);

	/** Draw our item.
	 * \param  graphics The graphics context to draw on
	 */
	virtual void Draw(Gdiplus::Graphics *graphics) = 0;

	/**
	 * Place this drawable relative to its parent
	 *
	 * This works hierarchically from top item down.
	 * \param offset Parent offset
	 * \param rotate Parent rotation
	 */
	void Place(Gdiplus::Point offset, double rotate);

	/**
	 * Add a child drawable to this drawable
	 * \param child The child to add
	 */
	void AddChild(std::shared_ptr<CDrawable> child);

	/**
	 * Test to see if we clicked on the image.
	 * \param pos Position to test
	 * \returns True if clicked on
	 */
	virtual bool HitTest(Gdiplus::Point pos) = 0;

	/**
	 * Tells if item is movable
	 * \returns False
	 */
	virtual bool IsMovable() { return false; }

	/**
	 * Move this drawable some amount
	 * \param delta The amount to move
	 */
	void Move(Gdiplus::Point delta);

	/** Set the drawable position
	 * \param pos The new drawable position*/
	void SetPosition(Gdiplus::Point pos) { mPosition = pos; }

	/** Get the drawable position
	 * \returns The drawable position*/
	Gdiplus::Point GetPosition() const { return mPosition; }

	/** Set the rotation angle in radians
	* \param r The new rotation angle in radians*/
	void SetRotation(double r) { mRotation = r; }

	/** Get the rotation angle in radians
	* \returns The rotation angle in radians*/
	double GetRotation() const { return mRotation; }

	/** Get the drawable name
	* \returns The drawable name */
	std::wstring GetName() const { return mName; }

	/** Get Pictured
	* \returns mParent The current parent */
	CDrawable* GetParent() { return mParent; }

	/** Set the parent
	* \param parent Parent to set */
	void SetParent(CDrawable *parent) { mParent = parent; }

protected:
	/**
	 * Constructor
	 * \param name The drawable name
	 */
	CDrawable(const std::wstring &name);

	/** Rotate a point by a given angle.
	* \param point The point to rotate
	* \param angle An angle in radians
	* \returns Rotated point
	*/
	Gdiplus::Point RotatePoint(Gdiplus::Point point, double angle);

	/// The actual postion in the drawing
	Gdiplus::Point mPlacedPosition = Gdiplus::Point(0, 0);

	/// The actual rotation in the drawing
	double mPlacedR = 0;

private:
	/// The drawable name
	std::wstring mName;

	/// The position of this drawable relative to its parent
	Gdiplus::Point mPosition = Gdiplus::Point(0, 0);

	/// The rotation of this drawable relative to its parent
	double mRotation = 0;

	/// The actor using this drawable
	CActor *mActor = nullptr;

	/// The parent
	CDrawable* mParent = nullptr;

	/// List of children
	vector<shared_ptr<CDrawable>> mChildren;
};
