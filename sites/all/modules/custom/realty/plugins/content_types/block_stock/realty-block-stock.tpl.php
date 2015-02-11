<div class="container-fluid container-fix" >
  <div class="row">
    <div id="stock"></div>

    <div class="col-xs-6 big-height fifty zero-padding big-stock">
      <?php if($priority_stock):?>
        <?php print render($priority_stock['image'])?>
      <?php endif?>
      <a href="<?php print $all_stock?>">
        <div class="col-xs-6 big-stock-quarter zero-padding title-black opacity-title-block">
          <?php print $micro_logo?>
          <div class="title-block">
            <h2>
              <?php print t('Stock')?>
            </h2>
            <p>
              <?php print t('move on')?>
            </p>
          </div>
        </div>
      </a>
      <div class="col-xs-6 big-stock-quarter right-place zero-padding big-stock-block">
        <div class="col-xs-12 big-stock-title zero-padding">
          <h2>
            <?php if($priority_stock):?>
              <?php print render($priority_stock['title'])?>
            <?php endif?>
          </h2>
        </div>
        <div class="col-xs-12 big-stock-body zero-padding">
          <div class="table-item">
            <?php if($priority_stock):?>
              <?php print $priority_stock['description']?>
            <?php endif?>
          </div>
        </div>
        <div class="col-xs-12 big-stock-button zero-padding">
          <?php if($priority_stock):?>
            <?php print $priority_stock['details']?>
          <?php endif?>
        </div>
        <div class="arrow-left-bigstock"></div>
      </div>
    </div>

    <div class="col-xs-3 big-height fifty-minus zero-padding ">
      <div class="col-xs-12 half-item zero-padding">
        <?php if(isset($stock[1])):?>
          <?php print $stock[1]['image']?>
        <?php endif?>
      </div>
        <div class="col-xs-12 second-half-item zero-padding v1stock">
          <div class="arrow-left-stock1"></div>
          <div class="col-xs-12 big-stock-title zero-padding cb-stock">
            <h2>
              <?php if(isset($stock[0])):?>
                <?php print $stock[0]['title']?>
              <?php endif?>
            </h2>
          </div>
          <div class="col-xs-12 big-stock-body zero-padding cb-stock">
            <div class="table-item">
              <?php if(isset($stock[0])):?>
                <?php print $stock[0]['description']?>
              <?php endif?>
            </div>
          </div>
          <div class="col-xs-12 big-stock-button zero-padding">
              <?php if(isset($stock[0])):?>
                <?php print $stock[0]['details']?>
              <?php endif?>
          </div>
        </div>
    </div>

    <div class="col-xs-3 big-height fifty-minus zero-padding ">
      <a href="#">
        <div class="col-xs-12 half-item zero-padding v2stock">
          <div class="arrow-left-stock2"></div>
          <div class="col-xs-12 big-stock-title zero-padding cb-stock">
            <h2>
              <?php if(isset($stock[1])):?>
                <?php print $stock[1]['title']?>
              <?php endif?>
            </h2>
          </div>
          <div class="col-xs-12 big-stock-body zero-padding cb-stock">
            <div class="table-item">
              <?php if(isset($stock[1])):?>
                <?php print $stock[1]['description']?>
              <?php endif?>
            </div>
          </div>
          <div class="col-xs-12 big-stock-button zero-padding">
            <?php if(isset($stock[1])):?>
              <?php print $stock[1]['details']?>
            <?php endif?>
          </div>
        </div>
      </a>
      <div class="col-xs-12 second-half-item zero-padding">
        <?php if($stock[0]):?>
          <?php print $stock[0]['image']?>
        <?php endif?>
      </div>
    </div>
  </div>

</div>
