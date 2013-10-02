#include "treeitem.h"

TreeItem::TreeItem(Analyzer *an, const QList<QVariant> &data, TreeItem *parent, int off){
    parentItem = parent;
    itemData = data;
    BoxFactory bf(an);
    if(!(data.value(0).toString()=="Name")) {
        try {
            box= bf.getBox( data.value(1).toUInt(),data.value(0).toString(),off ) ;
        }
        catch(NoSuchABoxException) {}
    }
}
////////////////////////////////////////////////////////////////////////////////////////////
TreeItem::~TreeItem(){
    qDeleteAll(childItems);
    delete parentItem;
}
////////////////////////////////////////////////////////////////////////////////////////////
void TreeItem::appendChild(TreeItem *item){
    childItems.append(item);
}
////////////////////////////////////////////////////////////////////////////////////////////
TreeItem *TreeItem::child(int row){
    return childItems.value(row);
}
////////////////////////////////////////////////////////////////////////////////////////////
int TreeItem::childCount() const{
    return childItems.count();
}
////////////////////////////////////////////////////////////////////////////////////////////
int TreeItem::columnCount() const{
    return itemData.count();
}
////////////////////////////////////////////////////////////////////////////////////////////
QVariant TreeItem::data(int column) const{
    return itemData.value(column);
}
////////////////////////////////////////////////////////////////////////////////////////////
TreeItem *TreeItem::parent(){
    return parentItem;
}
////////////////////////////////////////////////////////////////////////////////////////////
int TreeItem::row() const {
    if (parentItem)
        return parentItem->childItems.indexOf(const_cast<TreeItem*>(this));
    return 0;
}


