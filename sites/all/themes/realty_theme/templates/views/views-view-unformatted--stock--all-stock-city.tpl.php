<div class="container fin margin-bottom">
  <?php if (isset($stocks)): ?>
    <?php foreach($stocks as $stock):?>
      <a href="<?php print $stock['link']?>" class="col-xs-10 allstock-item zero-padding">
        <?php print $stock['image']?>
        <h3>
          <?php print $stock['title']?>
        </h3>
          <?php print $stock['body']?>
      </a>
    <?php endforeach;?>
  <?php endif;?>
</div>