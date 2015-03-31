<div class="col-xs-12 allcomplex-filter">
</div>
<div class="container fin margin-bottom">
  <?php if (isset($news)): ?>
    <?php foreach($news as $new):?>
      <a href="<?php print $new['link']?>" class="col-xs-10 allstock-item zero-padding">
        <?php if (isset($new['image'])):?>
          <?php print $new['image']?>
        <?php endif;?>
        <h3>
          <?php print $new['title']?>
        </h3>
        <?php print $new['body']?>
      </a>
    <?php endforeach;?>
  <?php endif;?>
</div>