#ifndef _TITAN_MAP_QT_ROTATE_LAYER_TOOL_H_
#define _TITAN_MAP_QT_ROTATE_LAYER_TOOL_H_

#include "MapTool.h"

namespace titan {
namespace map {
namespace qt {

#define ROTATE_LAYER_TOOL_NAME "RotateLayerTool"

class LIB_IMGMAP RotateLayerTool : public MapTool
{
public:
	RotateLayerTool();

	virtual std::string GetName() const;

	void SetCurrentLayer(const LayerPtr layer);

	virtual void DrawTool(QPaintDevicePtr dc);

	virtual bool IsDrawable() const;

	virtual void OnLButtonDown(quint32 flags, const QPoint& point);

	virtual void OnLButtonUp(quint32 flags, const QPoint& point);

	virtual void OnMouseMove(quint32 flags, const QPoint& point);

	virtual void OnMouseWheel(quint32 flags, short delta, const QPoint& point);

public:
	typedef boost::signals2::signal<void(double)> RotateDegreeChangedEvent;
	RotateDegreeChangedEvent RotateDegreeChanged;

private:
	void RebuildLayer(QPaintDevicePtr);
private:
	LayerPtr cur_layer;
	QPaintDevicePtr rotate_layer;

	QPoint start_pos;
	QPoint end_pos;

	bool is_pressed;

	QPoint tmp_end;

	double rotate_deg;
};

typedef boost::shared_ptr<RotateLayerTool> RotateLayerToolPtr;

}
}
}

#endif