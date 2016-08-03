#include "RotateLayerTool.h"
#include "MapViewer.h"
#include "Layer.h"

namespace titan {
namespace map {
namespace qt {

RotateLayerTool::RotateLayerTool()
	: MapTool(MapCursorSketch)
{
	is_pressed = false;
	rotate_layer.reset();
	rotate_deg = 0.0;
}

std::string RotateLayerTool::GetName() const
{
	return ROTATE_LAYER_TOOL_NAME;
}

void RotateLayerTool::SetCurrentLayer(const LayerPtr layer)
{
	cur_layer = layer;
}

void RotateLayerTool::DrawTool(QPaintDevicePtr dc)
{
	QWidget* main_win = GetMapViewer()->GetWidget();
	Viewport view = GetMapViewer()->GetViewport();
	QSize size = view.GetViewportSize();

	RebuildLayer(dc);

	QPainter painter(dc.get());

	painter.save();
	painter.translate(size.width() / 2, size.height() / 2);
	painter.rotate(rotate_deg);
	painter.translate(-size.width() / 2, -size.height() / 2);
	painter.drawPixmap(0, 0, *(QPixmap*)rotate_layer.get());
	painter.restore();

	for (int row = 0; row < size.width(); row += 60)
		for (int col = 0; col < size.height(); col += 60) {
			painter.drawLine(QPoint(0, col), QPoint(size.width(), col));
			painter.drawLine(QPoint(row, 0), QPoint(row, size.height()));
		}

	painter.setPen(QPen(QBrush(Qt::red), 3));
	painter.drawLine(QPoint(0, size.height() / 2), QPoint(size.width(), size.height() / 2));
	painter.drawLine(QPoint(size.width() / 2, 0), QPoint(size.width() / 2, size.height()));

	MapTool::DrawTool(dc);
}

bool RotateLayerTool::IsDrawable() const
{
	return true;
}

void RotateLayerTool::OnLButtonDown(quint32 flags, const QPoint& point)
{
	is_pressed = true;
	start_pos = point;

	tmp_end = point;

//	ÉèÖÃÍ¼²ãÐý×ª
///	if (cur_layer)
///		cur_layer->SetRotation(rotate_deg);
}

void RotateLayerTool::OnLButtonUp(quint32 flags, const QPoint& point)
{
	is_pressed = false;
}

void RotateLayerTool::OnMouseMove(quint32 flags, const QPoint& point)
{
	if (!is_pressed)
		return;
	end_pos = point;

	QSize size = GetMapViewer()->GetWidget()->size();
	QPoint central_pos(size.width() / 2, size.height() / 2);

	QPoint start_edge(start_pos.x() - central_pos.x(), central_pos.y() - start_pos.y());
	QPoint end_edge(end_pos.x() - central_pos.x(), central_pos.y() - end_pos.y());
	QPoint start_end = start_pos - end_pos;

	double start_edge_len = std::sqrt(1.0*(start_edge.x() * start_edge.x() + start_edge.y() * start_edge.y()));
	double end_edge_len = std::sqrt(1.0*(end_edge.x() * end_edge.x() + end_edge.y() * end_edge.y()));
	double start_end_len_2 = 1.0 * (start_end.x() * start_end.x() + start_end.y() * start_end.y());

	double cosa = (start_edge_len * start_edge_len + end_edge_len * end_edge_len - start_end_len_2) / (2 * start_edge_len * end_edge_len);
	double delta = std::acos(cosa) * 180 / 3.14;
	
	double cross = (end_edge.y() - start_edge.y()) * (0 - start_edge.x()) - (0 - start_edge.y()) * (end_edge.x() - start_edge.x());
	if (cross <= 0)
		delta = -delta;

	rotate_deg += delta;
	start_pos = point;

	RotateDegreeChanged(delta);
	RefreshTool();
}

void RotateLayerTool::OnMouseWheel(quint32 flags, short delta, const QPoint& point)
{
	QSize size = GetMapViewer()->GetWidget()->size();
	QPoint central_pos(size.width() / 2, size.height() / 2);

	MapTool::OnMouseWheel(flags, delta, central_pos);
}

void RotateLayerTool::RebuildLayer(QPaintDevicePtr dc)
{
	if (!cur_layer)
		return;

	const Viewport& view = GetMapViewer()->GetViewport();
	boost::shared_ptr<QPixmap> tmp_layer(new QPixmap(QSize(view.GetViewportSize())));
	tmp_layer->fill(GetMapViewer()->GetBackgroundColor());

	rotate_layer = tmp_layer;

	cur_layer->DrawLayer(rotate_layer, view, DrawPhaseGeography);
}

}
}
}