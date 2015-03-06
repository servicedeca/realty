<div class="col-xs-9 fiftyplus height zero-padding">
  <?php if(!empty($news)):?>
    <?php foreach($news as $new):?>
      <div class="col-xs-4 newsitem">
        <div class="news-item-title">
          <div>
            <?php print $new['date']?>
          </div>
          <?php print $new['title']?>
        </div>
        <div class="news-body news-border">
          <p>
            <?php print $new['description']?>
          </p>
        </div>
        <div class="news-item-footer">
          <?php print $new['details']?>
        </div>
      </div>
    <?php endforeach?>
  <?php endif?>
</div>
